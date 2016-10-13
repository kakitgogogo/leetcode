class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int mid=(n+m)/2+(n+m)%2;
        if((n+m)%2==1) return findK(nums1,nums2,0,0,mid);
        else return (findK(nums1,nums2,0,0,mid)+findK(nums1,nums2,0,0,mid+1))*1.0/2;
    }
private:
	int findK(vector<int>& nums1, vector<int>& nums2,int i1,int i2,int k)
	{
		int n1=nums1.size()-i1,n2=nums2.size()-i2;
		if(n1>n2) return findK(nums2,nums1,i2,i1,k);
		else if(n1==0) return nums2[k-1];
		else if(k==1) return min(nums1[i1],nums2[i2]);
		
		int j1=min(k/2,n1);
		int j2=k-j1;
		if(nums1[i1+j1-1]<nums2[i2+j2-1]) return findK(nums1,nums2,i1+j1,i2,k-j1);
		else if(nums1[i1+j1-1]>nums2[i2+j2-1]) return findK(nums1,nums2,i1,i2+j2,k-j2);
		else return nums1[i1+j1-1];
	}
};
