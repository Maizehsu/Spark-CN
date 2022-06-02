class Solution {
    public int numDifferentIntegers(String word) {
        HashSet<String> set = new HashSet<String>();
        String[] strArr = word.split("[a-z]+");
        //把数字挑出来
        for(int i = 0; i < strArr.length; i++){
            if(strArr[i].length()==0) 
                continue;
            //跳过空字符 如果是开头或者结尾是字母可能会出现这种情况
            while(strArr[i].length() > 1 && strArr[i].charAt(0) == '0'){
                strArr[i] = strArr[i].substring(1);
            }
            //一直删第一个字母一直到不是0为止
            set.add(strArr[i]);
            //无脑添加到hashset里面
        }
        return set.size();
    }
}
