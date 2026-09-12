function NewPromise(executorFunction) {
    // let the state of the promise be 'PENDING' initially

    let state = 'PENDING';
    let value = undefined;
    let handlers = []; // Stores { onFulfilled, onRejected, resolve, reject } 

    function resolve(result) {
        if (state !== 'PENDING') return;

        // If resolved value is itself a promise, adopt its state
        if (result && typeof result.then === 'function') {
            return result.then(resolve, reject);
        }

        state = 'FULFILLED';
        value = result;
        executeHandlers();
    }

    function reject(error) {
        if (state !== 'PENDING') return;

        state = 'REJECTED';
        value = error;
        executeHandlers();
    }

    // in this function, we check if the state is still 'PENDING'. If it is, we return early and do nothing. If the state has changed to either 'FULFILLED' or 'REJECTED', we proceed to execute the handlers. the state fulfilled or rejected is derermined by the resolve and reject functions, which are called when the promise is resolved or rejected, respectively. The executeHandlers function is responsible for executing the appropriate handlers based on the current state of the promise.
    //  We use queueMicrotask to ensure that the handlers are executed asynchronously, simulating the behavior of native promises. We then loop through the handlers array, shifting each handler off the array and executing its onFulfilled or onRejected callback based on the current state. If a callback is provided, we call it and resolve or reject the next promise in the chain accordingly. If no callback is provided, we simply pass along the value or error to the next promise.

    function executeHandlers() {
        if (state === 'PENDING') return;

        // Run handlers asynchronously (simulating microtask execution)
        queueMicrotask(() => {
            while (handlers.length > 0) {
                // handlers.shift removes the first handler from the array and returns it
                const handler = handlers.shift();

                if (state === 'FULFILLED') {
                    if (typeof handler.onFulfilled === 'function') {
                        try {
                            const res = handler.onFulfilled(value);
                            handler.resolve(res);
                        } catch (err) {
                            handler.reject(err);
                        }
                    } else {
                        handler.resolve(value); // Pass value along if no callback provided
                    }
                } else if (state === 'REJECTED') {
                    if (typeof handler.onRejected === 'function') {
                        try {
                            const res = handler.onRejected(value);
                            handler.resolve(res);
                        } catch (err) {
                            handler.reject(err);
                        }
                    } else {
                        handler.reject(value); // Pass error along if no callback provided
                    }
                }
            }
        });
    }

    this.then = function(onFulfilled, onRejected) {
        return new NewPromise((nextResolve, nextReject) => {
            handlers.push({
                onFulfilled,
                onRejected,
                resolve: nextResolve,
                reject: nextReject
            });
            executeHandlers();
        });
    };

    this.catch = function(onRejected) {
        return this.then(null, onRejected);
    };

    // Execute the executor function immediately upon instantiation
    try {
        executorFunction(resolve, reject);
    } catch (err) {
        reject(err);
    }
}