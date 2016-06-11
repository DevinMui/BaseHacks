var app = require("express")()
var body_parser = require("body-parser")

var flight = false

app.get('/', function(req, res){
	res.send("kys")
})

app.get('/sandwich', function(req, res){
	// turn on arduino
	// turn on drone
	// fly drone to x location
	flight = true
	res.send(flight)
})

app.get('/sandwich_done', function(req, res){
	flight = false
	res.send(flight)
})

app.listen(3000, function () {
  console.log('app running');
});