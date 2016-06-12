var arDrone = require('ar-drone');
var client  = arDrone.createClient();

client.takeoff(function(){
	client.front(0.1)
	setTimeout(function(){
		client.front(0)
		client.land()
	}, 2000)
})