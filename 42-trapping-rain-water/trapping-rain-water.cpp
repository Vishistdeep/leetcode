class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
    int n=height.size();

	for(int i = 1; i < n - 1; i++)
	{
		int result = 0;

    	int lMax[n];
    	int rMax[n];

    	lMax[0] = height[0];
    	for(int i = 1; i < n; i++)
    		lMax[i] = max(height[i], lMax[i - 1]);


    	rMax[n - 1] = height[n - 1];
    	for(int i = n - 2; i >= 0; i--)
    		rMax[i] = max(height[i], rMax[i + 1]);

    	for(int i = 1; i < n - 1; i++)
    		result = result + (min(lMax[i], rMax[i]) - height[i]);
    	
    	return result;
	}

	return result;
      
       /* int n = height.size()-1;
        if(height.size()==1){
            return 0;
        }

        int m = *max_element(height.begin(),height.end());
        int z;
        for(int i=0;i<height.size();i++){
            if(height[i]==m){
                z = i;
            }
        }

        int total = 0;
        int max1 = height[0];
        int a;
        for(int i=1;i<=z;i++){
            if(max1<height[i]){
                max1 = height[i];
            }
            else{
                a = max1 - height[i];
                total = total + a;
            }
        }
        
        int max2 = height[n];
        int y;
        for(int i=n-1;i>z;i--){
            if(max2<height[i]){
                max2 = height[i];
            }
            else{
                y = max2 - height[i];
                total = total + y;
            }
        }
        return total; */ 
    }
};