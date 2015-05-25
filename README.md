# Thrift on iOS

An example on accessing a [Thrift](https://thrift.apache.org/) API from an iOS app.


## Building the interfaces

Whenever you change a Thrift interface definition, you need to update the generated code for the languages you're using. In our case, we want to build NodeJS and Cocoa bindings:

```
thrift -o client/ThriftTest --gen cocoa thrift/messaging-service.thrift 
thrift -o server --gen js:node thrift/messaging-service.thrift 
```

*You usually might not want to version-control the generated code, but generate it during build/compile time instead.* The code is included here for a quick reference on what it looks like.


## Running the server

To run the server:

```
cd server
npm install
npm start
```

If you're curious, there's also a NodeJs-based client you can try out by simply running `npm run client`


## Compiling the client


To test this on a real device, deploy the server code to your hosting of choice (eg. Heroku) and change the server URL on client to point to it.