//
//  PostViewController.h
//  TwitterFon
//
//  Created by kaz on 7/16/08.
//  Copyright 2008 naan studio. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TwitterClient.h"
#import "Message.h"
#import "ProgressWindow.h"
#import "FolloweesViewController.h"

@interface PostViewController : UIViewController <UIImagePickerControllerDelegate, UINavigationControllerDelegate, UIActionSheetDelegate>
{
    IBOutlet UITextView*        text;
    IBOutlet UILabel*           charCount;
    IBOutlet UIWindow*          postWindow;
   	IBOutlet ProgressWindow*    progressWindow;

    IBOutlet UIBarButtonItem*   sendButton;
    IBOutlet UIBarButtonItem*   locationButton;
    IBOutlet UIBarButtonItem*   photoButton;
    
    UIImage*                    selectedPhoto;
    float                       latitude, longitude;
    
    NSObject*                   appDelegate;
    TwitterClient*              post;
    BOOL                        didPost;
    BOOL                        isDirectMessage;
    NSRange                     textRange;
    
    UINavigationController*     navigation;
    FolloweesViewController*    FolloweesViewController;
}

@property(nonatomic, assign) UINavigationController* navigation;
@property(nonatomic, assign) NSObject* appDelegate;
@property(nonatomic, retain) UIImage*  selectedPhoto;

- (void)startEditWithString:(NSString*)message;
- (void)startEditWithURL:(NSString*)URL;
- (void)startEdit;
- (void)checkProgressWindowState;
- (void)friendsViewDidSelectFriend:(NSString*)screenName;
- (void)friendsViewDidDisappear;
- (void)imagePickerControllerDidDisappear;

- (void) setCharCount;
- (void) saveTweet;

- (IBAction) cancel:  (id) sender;
- (IBAction) send:    (id) sender;
- (IBAction) clear:   (id) sender;
- (IBAction) friends: (id) sender;
- (IBAction) photos:  (id) sender;
- (IBAction) location:(id) sender;
@end
