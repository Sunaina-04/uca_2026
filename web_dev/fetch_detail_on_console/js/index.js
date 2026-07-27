// Starts the worker, listens for messages from it, and logs the output to the console.

let worker = new Worker ('web_worker.js');
worker. onmessage = (e) => {
    if (e.data.error){
        console.error(e.data.error);
    }else{
        for (let user of e.data){
            console.log (user.name);
            console.log (user.active);
        }
    }
};
