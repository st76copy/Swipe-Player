//
//  SwipeView.h
//  Swipe Player
//
//  Created by Clayton Rieck on 2/26/14.
//  Copyright (c) 2014 CLA. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MediaPlayer/MediaPlayer.h>
#import <AVFoundation/AVFoundation.h>
#import <AudioToolbox/AudioToolbox.h>

@protocol SwipeViewDelegate <NSObject>

- (void) performSongListSegue:(id)sender;

@end

@interface SwipeView : UIView<UIGestureRecognizerDelegate>
{
    CGFloat screenHeight;
//    NSArray* musicCollections;
    
    long currentSongIndex;
    double volumeLevel;
    double volumeSensitivity;
}

@property(nonatomic, strong) id<SwipeViewDelegate>delegate;

// music manager/item variables
@property(nonatomic, weak) MPMusicPlayerController* musicManager;
@property(nonatomic, strong) MPMediaQuery* mediaQuery;
@property(nonatomic, copy) MPMediaItem* currentSong;
@property(nonatomic, strong) NSArray* musicCollections;

// song information
@property(nonatomic, retain) IBOutlet UIImageView* cover;
@property(nonatomic, retain) IBOutlet UILabel* songTitle;
@property(nonatomic, retain) IBOutlet UILabel* songArtist;

// gestures
@property(nonatomic, strong) IBOutlet UITapGestureRecognizer* doubleTapGesture;
@property(nonatomic, strong) IBOutlet UIPanGestureRecognizer* panGesture;
@property(nonatomic, strong) IBOutlet UISwipeGestureRecognizer* leftSwipe;
@property(nonatomic, strong) IBOutlet UISwipeGestureRecognizer* rightSwipe;
@property(nonatomic, strong) IBOutlet UILongPressGestureRecognizer* longPress;

- (void)customInit;

- (IBAction)leftSwipeDetected:(id)sender;
- (IBAction)rightSwipeDetected:(id)sender;
- (IBAction)doubleTap:(id)sender;
- (IBAction)panUpDown:(UIPanGestureRecognizer*)panGesture;
- (IBAction)longPressDown:(UIGestureRecognizer*)longPressGesture;

- (void)handleNowPlayingItemChanged:(id)notification;
- (void)handleVolumeChangedFromOutsideApp:(id)notification;

- (void)setCoverArtAndInfo:(MPMediaItem*)current;
@end
