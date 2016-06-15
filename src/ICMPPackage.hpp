#ifndef ICMPPackageH
#define ICMPPackageH
#include "ipv4.hpp"
#include <string>
#include <sstream>
#include <vector>
class ICMPPackage {
private:
public:
    ipv4* src_IP;
    ipv4* srcHop_IP;
    ipv4* dst_IP;
    ipv4* dstHop_IP;
    string srcHop_MAC,srcHop_Name,dstHop_MAC,dstHop_Name;
    string message,type;
    int TTL;
    //ICMPPackage(src_IP,srcHop_IP,srcHop_MAC,srcHop_Name,dst_IP,dstHop_IP,dstHop_MAC,dstHop_Name,message,type,ttl)
    ICMPPackage(ipv4* src,ipv4* srcHpI,string srcM,string srcN,ipv4* dst,ipv4* dstHpI,string dstM,string dstN,string m,string t,int _ttl)
                :src_IP(src),srcHop_IP(srcHpI),srcHop_MAC(srcM),srcHop_Name(srcN)
                ,dst_IP(dst),dstHop_IP(dstHpI),dstHop_MAC(dstM),dstHop_Name(dstN)
                ,message(m),type(t),TTL(_ttl){}

    void updateDataLinkInfo(string srcHopName,string srcHopMAC,string dstHopName,string dstHopMAC);
    string toString();

    static ICMPPackage echoRequest(ipv4* srcIP,ipv4* dstIP,string m, int _ttl = 8){
        ICMPPackage request(srcIP,nullptr,"","",dstIP,nullptr,"","",m,"request",_ttl);
        return request;
    }

    static ICMPPackage echoReply(ipv4* srcIP,ipv4* dstIP,string m, int _ttl = 8){
        ICMPPackage reply(srcIP,nullptr,"","",dstIP,nullptr,"","",m,"reply",_ttl);
        return reply;
    }

    static ICMPPackage remountMessage(vector<ICMPPackage> packages){
        //TODO: Implement proper remountMessage....
        return packages[0];
    }

    static vector<ICMPPackage> sliceMessage(ICMPPackage package,int maxMTU){
        vector<ICMPPackage> packages;
        if(maxMTU > 0){
            //TODO: Implement proper sliceMessage....
        }else{
            packages.push_back(package);
        }
        return packages;
    }

    ~ICMPPackage(){
    }
};
#endif