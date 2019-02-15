#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>

#include "nfuse.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using nfuse::Call;
using nfuse::Tag;
using nfuse::IOSpace;

class IOSpaceClient {
 	public:
  		IOSpaceClient(std::shared_ptr<Channel> channel)
      		: stub_(IOSpace::NewStub(channel)) {}

  		// Assambles the client's payload, sends it and presents the response back
  		// from the server.
  		bool NullPingServer() {
  	  		Call reply;
  	  		Call request;

    		// Context for the client. It could be used to convey extra information to
    		// the server and/or tweak certain RPC behaviors.
    		ClientContext context;

    		// The actual RPC.
    		Status status = stub_->NullPing(&context, request, &reply);

    		// Act upon its status.
    		if (status.ok()) {
      			return true;
    		} else {
      			return false;
    		}
  		}

 	private:
  		std::unique_ptr<IOSpace::Stub> stub_;
};

int main(int argc, char** argv) {
  	// Instantiate the client. It requires a channel, out of which the actual RPCs
  	// are created. This channel models a connection to an endpoint (in this case,
  	// localhost at port 50051). We indicate that the channel isn't authenticated
  	// (use of InsecureCredentials()).
  	IOSpaceClient ioSpace(
      		grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
  	auto reply = ioSpace.NullPingServer();
  	std::cout << "Greeter received: " << reply << std::endl;

  	return 0;
}
