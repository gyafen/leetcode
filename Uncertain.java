// package DCI;

import java.io.*;
import java.math.BigDecimal;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Uncertain {
    public static List<String> readFile(String fileName) throws IOException {
        List<String> result = new ArrayList<String>();
        FileInputStream is = new FileInputStream(fileName);
        BufferedReader reader = new BufferedReader(new InputStreamReader(is));
        String content = null;
        while ((content = reader.readLine()) != null) {
            String[] strings=content.split(" ");
            StringBuilder sb=new StringBuilder();
            Random random=new Random();
            DecimalFormat decimalFormat=new DecimalFormat("0.000");
            String s=decimalFormat.format(random.nextDouble()/2+0.5);
            sb.append(s).append(" ").append(strings.length).append(" ").append(content);
            result.add(sb.toString());

        }   

        reader.close();
        return result;
    }

    public static void main(String[] args) throws IOException {


        List<String> contents;
        String input="USCensus.txt";
        String output="USCensus_3500.txt";
        contents = readFile(input);
        File file = new File(output);
        BufferedWriter writer = new BufferedWriter( new FileWriter(file));

        int num=3500,max=0;
        for(int i=0;i<num;i++)
        {
            String[] strings=contents.get(i).split(" ");
            max=Math.max(max,Integer.valueOf(strings[strings.length-1]));
        }

        //写入第一行
        StringBuilder sb=new StringBuilder();
        sb.append(num).append(" ").append(max);
        writer.write(sb.toString()+"\r\n");

        //写入列表，列表是原来读入的文件
        for(int i=0;i<num;i++) {
            writer.write(contents.get(i));
            writer.write("\r\n");//写入换行符
        }

        writer.close();
    }
}
