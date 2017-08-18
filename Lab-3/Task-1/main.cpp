#include <bits/stdc++.h>
using namespace std;

#define H_LEN 10

struct packet {
	int pkt_size;
	string message;
};

packet *pkts;
int num_packets;

void frag(int n, string msg, int MTU) {
	int eff_MTU = MTU - H_LEN;
	int sent_bytes = eff_MTU / 8;

	if(sent_bytes < 1) {
		cout<<"Fragmentation not possible, MTU is too small.\n";
	}

	int sent_bits = sent_bytes * 8;
	num_packets = n / sent_bits;
	if (n % sent_bits != 0) 
		num_packets++;
	
	pkts = new packet[num_packets];
	
	for(int i=0;i<num_packets-1;i++) {
		pkts[i].pkt_size=sent_bits;
		pkts[i].message="";
		for(int j=0;j<sent_bits;j++) {
			pkts[i].message=pkts[i].message + msg.at(i*sent_bits+j);
		}
	}
	
	int i=num_packets-1;
	pkts[i].pkt_size=n%sent_bits;
	pkts[i].message="";
	for(int j=0;j<(n%sent_bits);j++) {
		pkts[i].message=pkts[i].message + msg.at(i*sent_bits+j);
	}
	
	for(i=0;i<num_packets;i++) {
		cout<<"Packet "<<i+1<<": "<<pkts[i].message<<endl;
	}
}

void reass() {
	string ans="";

	for(int i=0;i<num_packets;i++)
		ans+=pkts[i].message;
	cout<<ans<<endl;
}

int main() {

	int len, MTU;
	string s;
	cout<<"Enter msg len: ";
	cin>>len;
	cout<<"Input message(in binary):";
	cin>>s;
	cout<<"Enter the MTU for fragmentation: ";
	cin>>MTU;
	cout<<"\nFragmentation starts\n";
	frag(len, s, MTU);
	cout<<"Fragmentation ends\n";

	cout<<"\nReassemble starts\n";
	reass();
	cout<<"Reassemble ends\n";
	return 0;
}