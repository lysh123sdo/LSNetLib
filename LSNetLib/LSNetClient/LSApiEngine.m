//
//  GTAApiEngine.m
//  GTANetProject
//
//  Created by Lyson on 16/3/17.
//  Copyright © 2016年 GTANetProject. All rights reserved.
//

#import "LSApiEngine.h"

@interface LSApiEngine()
@property (nonatomic , strong ) NSDictionary *parameters;
@end

@implementation LSApiEngine

#define TIMEOUT 8
/**
 *
 *
 *  @param url
 *  @param parameters
 *  @param files
 *  @param apiLevel

 *  @return
 */
-(instancetype)initWithUrl:(NSString*)url parameters:(NSDictionary*)parameters files:(NSArray*)files{

    if (self = [super init]) {
        
        _api = [url copy];
        _userInfo = [_api copy];
        _files = [files copy];
        self.parameters = parameters;
        
        if (![LSApiEngine isEmpty:self.host]) {
          _url = [NSString stringWithFormat:@"%@%@",self.host,self.api];
        }else{
            _url =  self.api;
        }
        
    }

    return self;
}

-(void)setUrl:(NSString*)url parameters:(NSDictionary*)parameters files:(NSArray*)files{

    _api = [url copy];
    _userInfo = [_api copy];
    _files = [files copy];
    self.parameters = parameters;
    
    if (![LSApiEngine isEmpty:self.host]) {
        _url = [NSString stringWithFormat:@"%@%@",self.host,self.api];
    }else{
        _url =  self.api;
    }
}

-(NSDictionary*)postBody{
    
    NSDictionary *encyBody =[self encryBody:_parameters];
    
    if (encyBody) {
        
        _parameters = encyBody;
    }
    
    NSDictionary *unicodeBody =[self unicodeBody:_parameters];
    
    if (unicodeBody) {
        
        _parameters = unicodeBody;
    }
    
    DLog(@"\n<<-----------请求-------------------\n Url == %@\n  DicStyle == %@\n------------------------------->>",self.url,_parameters);
    
    return _parameters;
}

-(NSString*)host{
    
    
    return nil;
}

-(NSDictionary*)encryBody:(NSDictionary*)body{


    return nil;
}

-(NSDictionary*)unicodeBody:(NSDictionary*)body{
    
    
    return nil;
}

- (NSTimeInterval)requestTimeoutInterval {
    return TIMEOUT;
}

+(BOOL)isEmpty:(NSString*)text{
    
    if ([text isKindOfClass:[NSNull class]] || text == nil  || text.length <=0) {
        
        return YES;
    }
    
    return NO;
}



-(void)dealloc{

    DLog(@"%@释放了",NSStringFromClass([self class]));

}
@end
