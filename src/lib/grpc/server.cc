#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>
#include <grpc/defs.h>
#include "nfuse.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using nfuse::Call;
using nfuse::Tag;
using nfuse::IOSpace;

// Logic and data behind the server's behavior.
class IOSpaceServiceImpl final : public IOSpace::Service {
  	Status NullPing(ServerContext* context, const Call* request,
            Call* reply) override {
    	reply->set_opcode(STATUS::SUCCESS);
    	reply->set_tags(0);
    	reply->set_value("");
    	reply->set_stamp(-1);
    	return Status::OK;
  	}
};

void RunServer() {
  	std::string server_address("0.0.0.0:50051");
  	IOSpaceServiceImpl service;

  	ServerBuilder builder;
  	// Listen on the given address without any authentication mechanism.
  	builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  	// Register "service" as the instance through which we'll communicate with
  	// clients. In this case it corresponds to an *synchronous* service.
  	builder.RegisterService(&service);
  	// Finally assemble the server.
  	std::unique_ptr<Server> server(builder.BuildAndStart());
  	std::cout << "Server listening on " << server_address << std::endl;

  	// Wait for the server to shutdown. Note that some other thread must be
  	// responsible for shutting down the server for this call to ever return.
  	server->Wait();
}

int main(int argc, char** argv) {
  	RunServer();

  	return 0;
}
