/*
 * Copyright (c) 2011 iRail vzw/asbl.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice, this list of
 *      conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright notice, this list
 *      of conditions and the following disclaimer in the documentation and/or other materials
 *      provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * The views and conclusions contained in the software and documentation are those of the
 * authors and should not be interpreted as representing official policies, either expressed
 * or implied, of iRail vzw/asbl.
 */

#import <Foundation/Foundation.h>
#import "IRailAPIDelegate.h"

#import "IRailStation.h"
#import "IRailVehicle.h"
#import "IRailLiveboard.h"
#import "IRailConnection.h"

@interface IRailAPI : NSObject {
    id<IRailAPIDelegate> delegate;
    NSString *providerUrl;
    NSString *lang;
}

@property(nonatomic, retain) id<IRailAPIDelegate> delegate;
@property(nonatomic, retain) NSString* lang;
@property(nonatomic, retain) NSString* providerUrl;

- (id)initWithDelegate:(id<IRailAPIDelegate>)aDelegate;
- (id)initWithDelegate:(id<IRailAPIDelegate>)aDelegate andLanguage:(NSString *)aLang;
- (id)initWithDelegate:(id<IRailAPIDelegate>)aDelegate language:(NSString *)aLang andProviderURL:(NSString *)aProvider;

- (void)callStationListCommand;
- (void)callInfoForVehicleCommandWithId:(NSString *)vehicleId;
- (void)callLiveboardCommandForStation:(NSString *)stationName;

- (void)callConnectionCommandWithDepartureName:(NSString *) fromName andArrivalName:(NSString *) toName;
- (void)callConnectionCommandWithDepartureName:(NSString *) fromName arrivalName:(NSString *) toName date:(NSDate *)date andDateType:(IRailDateType) dateType;

@end
