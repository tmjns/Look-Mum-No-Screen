'use strict'

const fs = require('fs'),
      url = require('url'),
      request = require('request');  

let server = require('http').createServer((req, res) => {
  
  let requesturl = req.url;
  requesturl = __dirname + '/data/example.json'; 
    
    fs.readFile(requesturl, (err, data) => {
      if (!err) {
        let dotoffset = requesturl.lastIndexOf('.');
        let mimetype = dotoffset == -1
                        ? 'text/plain'
                        : {
                            '.json' : 'json'
                        }[ requesturl.substr(dotoffset) ];
        res.statusCode = 200;
        res.setHeader('Content-type' , "application/json; charset=utf-8");
        res.setHeader('Cache-Control', 'no-cache');
        res.end(data);
        console.log(requesturl, mimetype);
      } 
      else {
        console.log ('file not found: ' + requesturl);
        res.writeHead(404, "Not Found");
        res.end();
      }
    });
  
});

server.listen(3000, () => { 
  console.log("Server is running at port 3000..."); 
});
