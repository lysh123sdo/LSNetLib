//
//  LSRequestModel.h
//  
//
//  Created by Lyson on 16/3/16.
//
//
//===============================
//模型实体基础类 ---用于获取、解析与映射数据 所有模型都继承该类
//===============================

#import <Foundation/Foundation.h>

#import "LSApiEngine.h"
#import "LSRequest.h"
#import "LSRequestStatusModel.h"

@interface LSRequestModel : NSObject<LSRequestDelegate>

@property (nonatomic , weak) NSString* userInfo;

@property (nonatomic , strong) void (^ success) (id model);
@property (nonatomic , strong) void (^ fail) (id model);
@property (nonatomic , strong) void (^ progress) (NSProgress *progress);

+(NSURLSessionTask*)postData:(NSString*)url parameters:(NSDictionary *)parameters success:(void(^)(id model))success fail:(void(^)(id model))fail;

+(NSURLSessionTask*)getData:(NSString*)url parameters:(NSDictionary *)parameters success:(void(^)(id model))success fail:(void(^)(id model))fail;

+(NSURLSessionTask*)uploadFiles:(NSString*)url parameters:(NSDictionary *)parameters files:(NSArray*)files success:(void(^)(id model))success fail:(void(^)(id model))fail progress:(void(^)(NSProgress *progress))progress;


/******获取一个Api处理器，如有需要不同的方式可继承LSApiEngine 重写对应的方法，获取一个新的工具*****/
-(LSApiEngine*)getApiEngine;

/*****获取解析器*******/
-(LSRequestStatusModel*)getResponseSerializer;

/**
 *  可以重载 用以实现多重嵌套的数据类型的映射、、、获取成一个字典，一一对应
 *
 */
-(NSDictionary*)getMapping;

@end
