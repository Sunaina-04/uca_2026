// Starts the worker, listens for messages from it, and logs the output to the console.

let worker = new Worker ('web_worker.js');
let usersDiv = document.getElementById('users');
worker. onmessage = (e) => {
    if (e.data.error){
        usersDiv.innerHTML = `<p>${e.data.error}</p>`;   
    }else{
        for (let user of e.data){
            usersDiv.innerHTML += `<p>${user.name} - ${user.active} <br></p>`;
        }
    }
};
