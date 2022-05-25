class Solution {
    public int countPairs(int[] deliciousness) {
        Map<Integer,Integer> map = new HashMap<>();
        long ans = 0;
        for (int i = 0;i < deliciousness.length;++i){
            for (int j = 0;j < 22;++j){
            //这里是22是因为两数之和2^20*2最大值可能是2^21 去循环这21个所有有可能出现的两数之和的情况去倒退另一个能够配对的数字
                int target = (int)Math.pow(2,j);
                //算出在这里的两数之和是多少
                if (target - deliciousness[i] < 0) 
                    continue;
                //因为constraint里面deliciousness[i]所有数字都大于零 所以<0直接continue
                if (map.containsKey(target - deliciousness[i])){
                    ans += map.get(target - deliciousness[i]);
                }
                //如果在map里面已经有已储存的配对数字，直接在ans里面加上配对数字出现的次数
            }
            map.put(deliciousness[i],map.getOrDefault(deliciousness[i],0) + 1);
            //把deliciousness[i]在map当中的次数加一
        }
        ans %= (1e9 + 7);
        return (int)ans;
    }
}

