var app = require("express")()
var body_parser = require("body-parser")
var PythonShell = require('python-shell')

app.get('/', function(req, res){
	res.send("kys")
})

app.get('/sandwich', function(req, res){
	PythonShell.run('ser.py', function (err) {
	  if (err) throw err
	  res.send("hell yeah")
	})
})

app.listen(3000, function () {
  console.log('app running')
});