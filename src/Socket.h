/*
 * Socket.h
 *
 *  Created on: Jun 13, 2014
 *      Author: jp
 */

#ifndef SOCKET_H_
#define SOCKET_H_

#include "Includes.h"

using namespace std;

class Socket {
private:
    string localName, remoteName;
    int socketFd, error;
    unsigned short port;
    struct sockaddr_in localAddress;
    struct sockaddr_in remoteAddress;
    Configuration* configuration;

public:
	Socket();
	virtual ~Socket();
    Socket(string localName);
    int fileDescriptor();
    in_addr getRemoteAddress();
    in_addr getLocalAddress();
    int activate(string server, unsigned short port);
    int passivate(unsigned short port);
    Socket * acceptOrCreateNew();
    int send(char * data, size_t size);
    int receive(char * data, size_t size);
    int destroy();

private:
    Socket(int socketFd, struct sockaddr_in localAddress, struct sockaddr_in remoteAddress, string owner);
	void setConfigurationFile(string fileName);
	void setLocalAddress(unsigned short port);
	void notifyErrorOn(string failingMethod);
	std::string socketInformation();
	void setRemoteAddress(unsigned short port, struct hostent* remote_info);
};

#endif /* SOCKET_H_ */
R