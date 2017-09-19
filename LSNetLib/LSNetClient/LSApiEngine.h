//
//  GTAApiEngine.h
//  GTANetProject
//
//  Created by Lyson on 16/3/17.
//  Copyright © 2016年 GTANetProject. All rights reserved.
//

//==================================================================================
//存放杂物
//==================================================================================

#import <Foundation/Foundation.h>

#ifdef DEBUG
#   define DLog(fmt, ...) {NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);}
#   define ELog(err) {if(err) DLog(@"%@", err)}
#else
#   define DLog(...)
#   define ELog(err)
#endif

@interface LSApiEngine : NSObject
{
    
    
}

@property (nonatomic , strong , readonly) NSString *host;
@property (nonatomic , strong , readonly) NSString *url;
@property (nonatomic , strong , readonly) NSString *api;
@property (nonatomic , strong , readonly) NSString *userInfo;
@property (nonatomic , strong , readonly) NSDictionary *postBody;
@property (nonatomic , strong , readonly) NSArray *files;


-(instancetype)initWithUrl:(NSString*)url parameters:(NSDictionary*)parameters files:(NSArray*)files;

-(void)setUrl:(NSString*)url parameters:(NSDictionary*)parameters files:(NSArray*)files;

/***编码服务器 ---有则重写定义一个***/
-(NSString*)getHost;

/***加密，需要加密重写此方法  body请求参数 不同的加密方式定义不同的Engine   返回的数据将作为新的请求参数***/
-(NSDictionary*)encryBody:(NSDictionary*)body;

/***编码，需要编码重写此方法   body请求参数   返回的数据将作为新的请求参数***/
-(NSDictionary*)unicodeBody:(NSDictionary*)body;

/**********超时设置************/
- (NSTimeInterval)requestTimeoutInterval;

@end
