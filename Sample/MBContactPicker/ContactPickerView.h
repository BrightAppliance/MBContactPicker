//
//  ContactPickerView.h
//  MBContactPicker
//
//  Created by Matt Bowman on 12/2/13.
//  Copyright (c) 2013 Citrrus, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MBContactPicker.h"

@protocol ContactCollectionViewDataSource <NSObject>

@required

@optional

- (NSArray *)contactModelsForCollectionView:(ContactCollectionView*)collectionView;

@end

@protocol ContactPickerDelegate <ContactCollectionViewDelegate>

@required

- (void)showFilteredContacts;
- (void)hideFilteredContacts;
- (void)updateViewHeightTo:(CGFloat)newHeight;

@end

@interface ContactPickerView : UIView <UICollectionViewDataSource, UICollectionViewDelegate, UITextFieldDelegateImproved, UITableViewDataSource, UITableViewDelegate, ContactCollectionViewDelegate>

@property (nonatomic, weak) id<ContactPickerDelegate> delegate;
@property (nonatomic, weak) id<ContactCollectionViewDataSource> contactDataSource;
@property (nonatomic, weak) id<ContactCollectionViewDelegate> contactDelegate;
@property (nonatomic, readonly) NSArray *contactsSelected;
@property (nonatomic) NSInteger cellHeight;
@property (nonatomic, copy) NSString *prompt;
@property (nonatomic) CGFloat maxVisibleRows;
@property (nonatomic) CGFloat currentContentHeight;

- (void)reloadData;

@end
