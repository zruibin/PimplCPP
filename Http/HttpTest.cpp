//
//  HttpTest.cpp
//  RBCHOW
//
//  Created by RBCHOW on 15/9/20.
//  Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
//

#include "HttpTest.h"

#include <iostream>
#include "CHttpClient.h"
#include <string.h>
#include "RBMarco.h"

namespace RBSpace {
 
void testHttpClient(void)
{
    using std::string;
    
    CHttpClient *httpClient = new CHttpClient();
    string *response = new string();
    httpClient->Get("http://www.oschina.net/", *response);
    
    DLog("response:%s\n", response->c_str());

    delete response;
    delete httpClient;
}



 
} // end of namespace


