var app = require("express")()
var body_parser = require("body-parser")
var arDrone = require('ar-drone');
var client  = arDrone.createClient();

app.get('/sandwich', function(req, res){
	// turn on arduino
	// turn on drone
	client.takeOff()
	// fly drone to x location
	res.send("coolios")
})

app.listen(3000, function () {
  console.log('app running');
});