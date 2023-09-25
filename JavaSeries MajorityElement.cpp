class Solution
{
    static int majorityElement(int a[], int size)
    {
        // your code here
        
        HashMap<Integer,Integer>map=new HashMap<>();
        for(int i=0;i<size;i++){
            map.put(a[i],map.getOrDefault(a[i],0)+1);
        }
        for(HashMap.Entry<Integer,Integer> it:map.entrySet()){
            if(it.getValue()>size/2){
                return it.getKey();
            }
        }
        return -1;
    }
}
