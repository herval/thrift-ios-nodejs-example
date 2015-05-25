#!/bin/sh

thrift -o client/ThriftTest --gen cocoa thrift/MessagingService.thrift 
thrift -o server --gen js:node thrift/MessagingService.thrift 