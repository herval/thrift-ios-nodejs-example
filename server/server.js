"use strict";

var Messaging = require("./lib/messagingService");

var port = process.env.PORT || 9090;

var server = new Messaging();

server.createServer().listen(port);