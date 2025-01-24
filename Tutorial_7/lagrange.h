/*******************************************************************************/
/**************************** lagrange.h *****************************/
/*******************************************************************************/
/* Function specifying langrage calculation                                    */
/*******************************************************************************/
# include "includes.h"
template <class V,class U> //class T,class Type>


double lagrange(vector<V>& vec1, vector<U>& vec2,const double &t)
{
	int n = vec1.size();
	
	vector <double> l(n+1);
	vector <double> p(n);
	
	l[0] = 1;
	p[0] = 0;
	
	for (int i=1; i <= n; ++i)													
	{																				
		for(int j = 1; j <= n; ++j)												
		{	
																					
		if( i != j  && j == 1)
		{
		
		l[j] = (t - vec2[j-1])/(vec2[i-1]-vec2[j-1]);	
		
		}
		
		else if( i !=j && j != 1) 		
		{
				
		l[j] = ((t - vec2[j-1])/(vec2[i-1]-vec2[j-1]))*l[j-1];										
		
		}
		else 
		{
			l[i] = l[j-1];
		}
		}
		
		p[i] = vec1[i-1]* l[n]+p[i-1];
		
	}
	
	return p[n];
	
}

