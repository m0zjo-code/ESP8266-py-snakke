# ESP8266-py-snakke
Simple script to demonstrate comunications between ESP8266 running the arduino core and a python script

This uses the python socket and thread library to open multiple connections 




                                                             +-------------------------------+
                                                             |                               |
                                      +----------------------+                               |
                                      |                      |   LAN/Internet etc            |
                                      |                      |   DNS is supported!           |
                                      |                      |                               +--------------+
+-------------------------------------+------+               |                               |              |
|                                            |               |                               |              |
|                                            |               |                               |              |
|                                            |               +-------------------------------+              |
|     Python Server                          |                                                              |
|                                            |                                                              |
|         Listening on port 8950             |                                                              |
|                                            |                                                              |
|                                            |                                                              |
|                                            |                                                              |
|                                            |                                                              |
|                                            |                                                              |
|                                            |                                                   +----------+-------------------+
+--------------------------------------------+                                                   |                              |
                                                                                                 |                              |
                                                                                                 |                              |
                                                                                                 |                              |
                                                                                                 |      ESP8266 running         |
                                                                                                 |      Arduino Core            |
                                                                                                 |                              |
                                                                                                 |                              |
                                                                                                 |                              |
                                                                                                 |                              |
                                                                                                 +------------------------------+

