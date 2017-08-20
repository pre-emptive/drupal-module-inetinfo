# drupal-module-inetinfo
Drupal 6 Internet Information Module

This module provides an API that produces hypertext links on hostnames and IP addresses. When clicked, these links 'pop up' a CSS based mini-window that loads Internet information about the hostname or IP address. The mini-window is provided by the excellent Floatbox tool.

Since this module is really only an API, it does very little by itself. To see it in action though, have a look at the Autoban Module or have a look at this screenshot.

Links produced by the API normally pop open the mini-window. However, if Javascript is not available, or the user elects to open the link in a new window or tab then the same content is available there. The actual content can be populated by Ajax requests (because hostname and Whois lookups can take a while to complete). Again, if Javascript is not available then a plain HTML page is served.

Currently, information provided includes:

* Forward and reverse DNS lookups
* GeoIP information
* Whois network/domain information

The DNS lookups are performed internally in PHP. The GeoIP and Whois lookups can be performed by shell commands or by Internet services (all configurable).
## The API

An example of the API access to the Internet Information module is as follows:
```
<?php
function mymodule_display_info() {
  $output = '';
  $address = '1.2.3.4';
  if(module_exists('inetinfo')) {
    $output .= module_invoke('inetinfo', 'l', $address);
  }
  return $output;
}
?>
```
The "l" function provided by the Internet Information module works almost the same as the Drupal API function of the same name. One exception is that there is no need to specify the destination of the link - the module calculates this base on the address supplied.
## Definition

`inetinfo_l($text, $path = '', $options = array())`
## Description

Formats a hostname or IP address into an internal Drupal HTTP link that points to Internet information for the specified host.
## Paramters

$text The hostname or IP address to provide information for. This is used as the "text" of the link, and the destination of the link is calculated from it.

$path A path for the link - if not blank will be used in place of the calculated link (and so information will not be provided, but the Floatbox popup will still be used).

$options An associative array of additional options, with the following keys:

* 'attributes' An associative array of HTML attributes to apply to the anchor tag.
* 'query' A query string to append to the link, or an array of query key/value properties.
* 'fragment' A fragment identifier (named anchor) to append to the link. Do not include the '#' character.
* 'absolute' (default FALSE) Whether to force the output to be an absolute link (beginning with http:). Useful for links that will be displayed outside the site, such as in an RSS feed.
* 'html' (default FALSE) Whether the title is HTML, or just plain-text. For example for making an image a link, this must be set to TRUE, or else you will see the escaped HTML.
* 'alias' (default FALSE) Whether the given path is an alias already.

## Return value

an HTML string containing a link to the given path.
