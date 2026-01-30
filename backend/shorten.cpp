#include "endpoints.h"
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>
using namespace std;
string uniqueId();
//mock endpoint
void shorten(string long_url){
    cout<<"Called from the shorten method: "<<long_url<<endl;
    /* Steps TODO: 
     * 1. check if exists in db (return the short url if already in db)
     * 2. if not create a new id for it in the db and then use the id to convert it
     *      into a short url
     * 3. add the short url, along with id and the long url in the db
     * 4. return the short url
     */

    //generating uniqueID
    string id = uniqueId();
    cout<<id<<endl;
}

string uniqueId(){
    boost::uuids::random_generator gen;

    boost::uuids::uuid id = gen();

    string s = boost::uuids::to_string(id);
    cout<<s<<endl;
    return s;
}
