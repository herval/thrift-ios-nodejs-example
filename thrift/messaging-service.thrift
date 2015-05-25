struct User {
  1: required i32 id
  2: required string name 
}

struct Message {
  1: required string body
  2: required User sender
  3: required i32 timestamp
}

struct UserCredentials {
  1: required string token
}

struct NewMessage {
  1: required UserCredentials sender
  2: required string body
  3: required i32 targetUserId
}


service Messaging {
  list<Message> fetchMessages(1: UserCredentials credentials),

  bool postMessage(1: NewMessage message),

  void ping(1: UserCredentials credentials)
}