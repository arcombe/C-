#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include "nameserverinterface.h"
#include "VNS.h"


using namespace std;


	VNS::VNS() {}


	VNS::~VNS() {
		server.clear();
	}

	/*
	 * Insert a name/address pair. Does not check if the name
	 * or address already exists.
	 */
	void VNS::insert(const HostName& hn, const IPAddress& adress){
		server.push_back(make_pair(hn, adress));
	}

	/*
	 * Remove the pair with the specified host name. Returns true
	 * if the host name existed and the pair was removed, false
	 * otherwise.
	 */
	bool VNS::remove(const HostName& hn){
		auto tmp = find_if(server.begin(), server.end(), [&hn](pair<HostName, IPAddress> &p) {return p.first == hn;});
		if (tmp == server.end()){
			return false;
		}
		server.erase(tmp);
		return true;
	}

	/*
	 * Find the IP address for the specified host name. Returns
	 * NON_EXISTING_ADDRESS if the host name wasn't in the name
	 * server.
	 */
	IPAddress VNS::lookup(const HostName& hn) const{
		auto tmp = find_if(server.begin(), server.end(), [&hn](const pair<HostName, IPAddress> &p) {return p.first == hn;});
		if (tmp != server.end()){
			return tmp->second;
		}
		return NON_EXISTING_ADDRESS;

	}

// int main(int argc, char const *argv[])
// {
// 	VNS v;
// 	v.insert("11", 11);
// 	v.insert("10", 111);
// 	cout << v.lookup("10") << endl;
// 	return 0;
// }
