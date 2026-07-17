/* to parse the http request need to 
 * 1.read it until the delimeter which is \r\n\r\n 
 * that means its the end of the headers and from the headers get the content length
 * and read the bytes based on that
 *
 * 2. that will be stored in a buffer then convert that into a istream
 * and then read it.
 *
 * 3 . read the body if content length is greater than 0 and add it to the struct
 * 4 . return that as the HTTP request headers as a struct 
 */
