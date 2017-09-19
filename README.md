# LSNetLib

1、开始使用需通过cocopod将支持库下载下来

2、使用网络库的时候直接继承LSRequestModel基类，

3、通过LSApiEngine配置请求URL

4、可自定义请求与解析的配置

  -(LSApiEngine*)getApiEngine{
  
    return "你的配置项"
    
  }
  
  -(LSRequestStatusModel*)getResponseSerializer{
  
    return "你的配置项"
  }
  
  
 
