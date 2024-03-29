/*
 * Authors:
 *  Landon Fuller <landonf@plausiblelabs.com>
 *  Damian Morris <damian@moso.com.au>
 *
 * Copyright (c) 2008-2010 Plausible Labs Cooperative, Inc.
 * Copyright (c) 2010 MOSO Corporation, Pty Ltd.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */


#import <Foundation/Foundation.h>

#import "PLCrashReportFormatter.h"

/**
 * Supported text output formats.
 *
 * @ingroup enums
 */
typedef enum {
    /** An iOS-compatible crash log text format. Compatible with the crash logs generated by the device and available
     * through iTunes Connect. */
    PLCrashReportTextFormatiOS = 0
} PLCrashReportTextFormat;


@interface PLCrashReportTextFormatter : NSObject <PLCrashReportFormatter> {
@private
    /** Text output format. */
    PLCrashReportTextFormat _textFormat;

    /** Encoding to use for string output. */
    NSStringEncoding _stringEncoding;
  
    NSString * _crashIdentity;
}

+ (NSString *) stringValueForCrashReport: (PLCrashReport *) report withTextFormat: (PLCrashReportTextFormat) textFormat;
+ (NSString *) stringValueForCrashReport: (PLCrashReport *) report
                          withTextFormat: (PLCrashReportTextFormat) textFormat
                           crashIdentity:(NSString **)crashIdentity;

@property (nonatomic, retain, readonly) NSString * crashIdentity;
- (id) initWithTextFormat: (PLCrashReportTextFormat) textFormat stringEncoding: (NSStringEncoding) stringEncoding;

@end
