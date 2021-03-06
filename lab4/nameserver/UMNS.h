/*
 * Interface NameServerInterface -- all name server implementations must
 * implement this interface.
 */
#ifndef UMNS_H
#define UMNS_H

#include <unordered_map>
#include <string>

class UMNS : public NameServerInterface {
public:
	
	UMNS() ;

	virtual ~UMNS() override;
	
	/*
	 * Insert a name/address pair. Does not check if the name
	 * or address already exists.
	 */
	virtual void insert(const HostName&, const IPAddress&) override;
	
	/*
	 * Remove the pair with the specified host name. Returns true
	 * if the host name existed and the pair was removed, false
	 * otherwise.
	 */
	virtual bool remove(const HostName&) override;
	
	/*
	 * Find the IP address for the specified host name. Returns
	 * NON_EXISTING_ADDRESS if the host name wasn't in the name
	 * server.
	 */
	virtual IPAddress lookup(const HostName&) const override;
private:

	std::unordered_map<HostName, IPAddress> server;

};
#endif



