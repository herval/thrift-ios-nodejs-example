"use strict";

var thrift = require("thrift");
var Messaging = require("./../gen-nodejs/Messaging");
var messagingTypes = require("./../gen-nodejs/messaging-service_types");

function MessagingService() {

  this.thriftInterface = {
    ping: function(credentials, result) {
      console.log(credentials);
      console.log("Received ping with credentials:", credentials.token);
      result();
    },

    fetchMessages: function(credentials, result) {
      var user1 = new messagingTypes.User({ id: 1, name: "Richie" });
      var user2 = new messagingTypes.User({ id: 2, name: "Floyd" });
      var messages = [
        new messagingTypes.Message({ body: "Hello!", sender: user1, timestamp: 1432558065 }),
        new messagingTypes.Message({ body: "Is it me you're looking for?", sender: user1, timestamp: 1432958065 }),
        new messagingTypes.Message({ body: "Is there anybody out there?", sender: user2, timestamp: 1532558065 }),
      ]

      result(null, messages);
    },

    postMessage: function(message, result) {
      console.log("Sent message: ", message.body, "to", message.targetUserId, "by", message.sender.token);
      result(null, true);
    }
  }


  this.createServer = function() {
    return thrift.createServer(
      Messaging, 
      this.thriftInterface, 
      {}
    );
  }

};

module.exports = MessagingService;