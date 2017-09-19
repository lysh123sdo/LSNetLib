//
//  GTABaseRequest.h
//  
//
//  Created by Lyson on 16/3/16.
//
//==================================================================================
//request base class , 
//==================================================================================


#import <Foundation/Foundation.h>
#import "LSApiEngine.h"



//====================================================
//==文件上传打包key值
//NSMutableDictionary *dic1 = [NSMutableDictionary new];
//
//[dic1 setValue:@"files1" forKey:@"com.gta.upload.name"];
//[dic1 setValue:@"png" forKey:@"com.gta.upload.type"];
//[dic1 setValue:@"files" forKey:@"com.gta.upload.key"];
//
//[dic1 setValue:path1 forKey:@"com.gta.upload.path"];
// [dic1,dic2]
//====================================================

/******文件上传的路径 ---本地文件路径 ******/
FOUNDATION_EXPORT NSString * const LSUploadFilePathKey;
/******上传的文件名 ******/
FOUNDATION_EXPORT NSString * const LSUploadFileNameKey;
/******文件上传的路径 上传文件类型******/
FOUNDATION_EXPORT NSString * const LSUploadFileTypeKey;
/******上传的key --用于取数据 ******/
FOUNDATION_EXPORT NSString * const LSUploadFileKeyKey;

@protocol LSRequestDelegate ;

@interface LSRequest : NSObject

/**
 *  对象用strong类型，防止delegate提前被释放 --
 */
@property (nonatomic , strong) id<LSRequestDelegate> delegate;
@property (nonatomic , strong) NSString *userInfo;
@property (nonatomic , strong) NSURLSessionTask *sessionTask;
@property (nonatomic , strong) LSApiEngine *engine;


/**
 *  提交文件
 *
 *  @param engine api处理器
 *  @param delegate 代理
 *
 *  @return 请求对象对象
 */
+(NSURLSessionTask*)uploadFileWithUrl:(LSApiEngine*)engine
                             delegate:(id<LSRequestDelegate>)delegate;

/**
 *  提交文本信息
 *
 *  @param engine api处理器
 *  @param delegate 代理
 *
 *  @return 请求对象对象
 */
+(NSURLSessionTask*)postData:(LSApiEngine*)engine
                    delegate:(id<LSRequestDelegate>)delegate;

/**
 *  提交文本信息
 *
 *  @param engine api处理器
 *  @param delegate 代理
 *
 *  @return 请求对象对象
 */
+(NSURLSessionTask*)getData:(LSApiEngine*)engine delegate:(id<LSRequestDelegate>)delegate;


/**
 *  更具API下载文件 --
 *
 *  @param engine api处理器
 *  @param delegate 代理
 *
 *  @return 请求对象对象
 */
+(NSURLSessionTask*)downLoadFiles:(LSApiEngine*)engine
                         delegate:(id<LSRequestDelegate>)delegate;

/**
 *  更具URL下载文件
 *
 *  @param url URL链接
 *  @param delegate 代理
 *
 *  @return 下载对象
 */
+(NSURLSessionTask*)downLoadFilesWithUrl:(NSString*)url
                                delegate:(id<LSRequestDelegate>)delegate;
@end


@protocol LSRequestDelegate <NSObject>


-(void)lsRequestFinish:(LSRequest*)request response:(id)responseObject;

-(void)lsRequestFail:(LSRequest*)request error:(NSError*)error;

-(void)lsRequest:(LSRequest*)request progress:(NSProgress*)progress;

-(void)lsRequest:(LSRequest *)request filePath:(NSURL*)filePath error:(NSError*)error;

-(NSURL*)lsRequestGetDestinationUrl:(LSRequest *)request response:(NSURLResponse*)response;
@end
