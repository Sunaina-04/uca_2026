// Runs in the background, fetches data from the API, checks for errors, and extracts the names and active statuses.

const xhr = new XMLHttpRequest();
xhr.onload = () => {
    if (xhr.status === 200 ){
        let users =JSON.parse(xhr.responseText);

        if (users.length === 0) {
            postMessage({error: 'No users found.'});
        } else {
            // extract usernames and active status, then send them back 
            let formattedUsers = [];

            for (let user of users){
                formattedUsers.push({
                    name: user.name,
                    active: user.active
                });
            }
            postMessage(formattedUsers);
        }
    }else{
        postMessage({error: 'Failed to fetch users from API.'});
    }
};

xhr.onerror = () => {
    postMessage({error : 'Network error occured.'});
};

xhr.open('GET','https://dummyapi.com/users');
xhr.send();