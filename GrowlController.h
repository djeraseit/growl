//
//  GrowlController.h
//  Growl
//
//  Created by Karl Adam on Thu Apr 22 2004.
//

#import <Foundation/Foundation.h>
#import "GrowlDisplayProtocol.h"

@protocol GrowlDisplayPlugin;

@interface GrowlController : NSObject {
	NSMutableDictionary			*_tickets;				//Application tickets
	NSLock						*_registrationLock;
	NSMutableArray				*_notificationQueue;
	NSMutableArray				*_registrationQueue;
	
	id<GrowlDisplayPlugin>		displayController;
}

+ (id) singleton;

- (BOOL)application:(NSApplication *)theApplication openFile:(NSString *)filename;

- (void) dispatchNotification:(NSNotification *)note;
- (void) dispatchNotificationWithDictionary:(NSDictionary *)dict;

- (void) loadTickets;
- (void) saveTickets;

- (void) preferencesChanged: (NSNotification *) note;

- (void) shutdown:(NSNotification *) note;

- (void) replyToPing:(NSNotification *) note;

@end

