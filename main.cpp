#include "Nacos.h"
#include <iostream>

using namespace std;
using namespace nacos;

int main() {
  Properties props;
  props[PropertyKeyConst::SERVER_ADDR] = "127.0.0.1:8848"; // Server address
  INacosServiceFactory *factory = NacosFactoryFactory::getNacosFactory(props);
  ResourceGuard<INacosServiceFactory> _guardFactory(factory);
  ConfigService *n = factory->CreateConfigService();
  ResourceGuard<ConfigService> _serviceFactory(n);
  NacosString ss = "";
  try {
    ss = n->getConfig("k", NULLSTR, 1000);
  } catch (NacosException &e) {
    cout << "Request failed with curl code:" << e.errorcode() << endl
         << "Reason:" << e.what() << endl;
    return -1;
  }
  cout << ss << endl;
  cout << "hello" << endl;
  return 0;
}
