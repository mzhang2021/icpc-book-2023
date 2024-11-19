/**
 * Author: chilli, Andrew He, Adamant
 * Date: 2019-04-27
 * Description: Given $n$ points (x[i], y[i]), computes an n-1-degree polynomial $p$ that
 *  passes through them: $p(x) = a[0]*x^0 + ... + a[n-1]*x^{n-1}$.
 * Time: O(n \log^2 n)
 */
#pragma once

#include "PolyBase.h"
#include "PolyIntegDeriv.h"
#include "PolyEvaluate.h"

poly interp(vector<num> x, vector<num> y) {
	int n=sz(x);
	vector<poly> up(n*2);
	rep(i,0,n) up[i+n] = poly({num(0)-x[i], num(1)});
	for(int i=n-1; i>0;i--) up[i] = up[2*i]*up[2*i+1];
	vector<num> a = eval(deriv(up[1]), x);
	vector<poly> down(2*n);
	rep(i,0,n) down[i+n] = poly({y[i]*(num(1)/a[i])});
	for(int i=n-1;i>0;i--) down[i] = down[i*2] * up[i*2+1] + down[i*2+1] * up[i*2];
	return down[1];
}
