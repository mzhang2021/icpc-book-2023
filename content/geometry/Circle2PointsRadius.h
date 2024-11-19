/**
 * Author: asksandipd
 * Source: https://github.com/asksandipd/ACM-ICPC-Libraries/blob/master/SandyzCodeZine/geometry.cpp#L369
 * Description: Finds a circle going through 2 points with a given radius.
 */

bool circle2ptsRad( double x1, double y1, double x2, double y2, double r, double ctr[2] )
{
    double d2 = ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 );
    double det = r * r / d2 - 0.25;
    if( det < 0.0 ) return false;
    double h = sqrt( det );
    ctr[0] = ( x1 + x2 ) * 0.5 + ( y1 - y2 ) * h;
    ctr[1] = ( y1 + y2 ) * 0.5 + ( x2 - x1 ) * h;
    return true;
}
