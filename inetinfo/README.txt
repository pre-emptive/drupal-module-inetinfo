Inetinfo - Show Internet Information for hostnames and IP addresses

Written by Ralph Bolton, September 2008
(C)2008 Pre-Emptive Limited

What is it?
-----------
Inetinfo is a Drupal module that provides a programming API. The API produces
hypertext links that when clicked draw a CSS over-layed window which loads
information about a hostname or IP address.

The API really only provides an l() function that works identically to the
Drupal API function of the same name. However, when used extra Javascript and
CSS items are added to the page which enable the popup functionality.

The module also provides the mechanism to display hostname/IP lookup
information, GeoIP information and 'whois' network information for a given
hostname or IP address.

How Does it Work?
-----------------

First, module developers use the inetinfo API. An example of this is:

  if(module_exists('inetinfo')) {
    $output .= module_invoke('inetinfo','l','74.6.17.154');
  } else {
    $output .= '174.6.17.154';
  }

In this example, the $output variable will have an IP address appended to it.
If the inetinfo module is present, then the IP address will be an HTTP link.
If clicked, the link will open a CSS overlay 'popup' window, and will load
internet information about the IP address.

Is Javascript is not enabled, or if the link is opened into a new window or
tab, then no CSS popup will open, but the information will load into the
new tab as normal.

What's in it?
-------------

The CSS popup functionality is provided by Floatbox by Byron McGregor
http://randomous.com/tools/floatbox/

The Whois functionality is provided by  php-whois by Mark Jeftovic,
David Saez Padros and Ross Golder.
http://sourceforge.net/projects/phpwhois

Additionally, whois and GeoIP information can be obtained via Internet
services.


