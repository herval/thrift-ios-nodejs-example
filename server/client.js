"use strict";

var thrift = require('thrift');
var Messaging = require('./gen-nodejs/Messaging');
var messagingTypes = require('./gen-nodejs/messaging-service_types');

var transport = thrift.TBufferedTransport()
var protocol = thrift.TBinaryProtocol()

var connection = thrift.createConnection("localhost", 9090, {
  transport : transport,
  protocol : protocol
});

connection.on("error", function(err) {
  assert(false, err);
});

var client = thrift.createClient(Messaging, connection);

var myCredentials = new messagingTypes.UserCredentials({ token: "DEADBEEF" });

client.ping(myCredentials, function(err, response) {
  console.log("ping");

  client.fetchMessages(myCredentials, function(err, response) {
    console.log("fetchMessages:", response);

    var newMessage = new messagingTypes.NewMessage({ sender: myCredentials, body: "Hello world", targetUserId: 123 });
    client.postMessage(newMessage, function(err, response) {
      console.log("postMessage:", response);
      connection.end();
    })
  });
});