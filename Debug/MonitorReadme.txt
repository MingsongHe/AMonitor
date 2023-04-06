MICROSOFT WORD 97 README FILE

(c) 1996 Microsoft Corporation. All rights reserved.

This document provides late-breaking or other information that
supplements the Microsoft Word 97 documentation. If you installed
Microsoft Word 97 with Microsoft Office 97, see also the
Microsoft Office 97 readme file (OfRead8.txt) for information
that is relevant to all Microsoft Office 97 products.

________________________________________________________________
CONTENTS

     INSTALLING MICROSOFT WORD 97
       IMPORTANT: Disable Virus Protection Before Running Setup
       Minimum System Requirements for Microsoft Word 97
       Requirements for Microsoft Word 97 with Windows NT
       Workstation 4.0
       Using Punctuation Characters in Directory Names May Cause
       Problems
       Microsoft Plus! Themes Patch
     MICROSOFT WORD 97 HELP AND GETTING RESULTS BOOK
       Help Topics Graphics Don't Print Clearly
       Correction to Getting Results Book
     WORKING WITH DOCUMENTS
       Missing Characters when Opening Macintosh and
       Multilingual Documents
       Cannot Edit a Word Document Embedded Object in Word 95
       Cannot Edit an Embedded Object Created in a Word 95
       Document After Saving in Word 97
       Cannot Undo Edit After Attaching a Template
       Mail Merge Errors in Microsoft Word 97 with Comma
       Separated Values or Tab Separated Values Files Exported
       from Microsoft Outlook 97
     WORKING WITH E-MAIL
       Using WordMail Templates
       Turning Off Word as E-mail Editor in Microsoft Exchange
       Vendor Independent Messaging (VIM) Not Supported on
       Windows NT Workstation
     MICROSOFT OFFICE 97 VALUPACK
       Microsoft Office 97 ValuPack Setup May Not Be Successful
       Without Administrative Permissions
       Microsoft Office 97 Sounds Don't Work with Windows NT
       Workstation 3.51
       Sharing Microsoft Word 97 Files with Earlier Versions of
       Microsoft Word
     PRINTING
       Solutions for Printing Drawing Objects
     MICROSOFT VISUAL BASIC FOR APPLICATIONS
       Changes to Code Examples
       InsertSymbol Method Has a Fourth Argument
       RevisedLinesColor Property
       Reload Method Not Available
       MsgBox Function
       ReSize Event
     MICROSOFT FORMS 2.0: ISSUES AND DOCUMENTATION CHANGES
       Methods
       Controls
       Events
       Properties
       Other Known Issues
       
________________________________________________________________
INSTALLING MICROSOFT WORD 97

IMPORTANT: Disable Virus Protection Before Running Setup
--------------------------------------------------------

Some virus protection programs, such as VSafe.com and Norton Anti-
Virus Autoprotect, can interfere with the Microsoft Word 97 Setup
program. If you use a virus protection program on your computer,
please disable it before running Setup. (You can re-enable the
virus protection program after Setup is complete.) Note: If your
virus-detection program starts automatically when you start
Windows, you can disable it by restarting Windows while holding
down the SHIFT key.


Minimum System Requirements for Microsoft Word 97
-------------------------------------------------

To use Microsoft Word 97, you need:

* Personal or Multimedia computer with a 486 or higher processor.
* Microsoft Windows 95 operating system or Windows NT Workstation
  3.51 with Service Pack 5 or later (will not run on earlier
  versions).
* 8 MB of memory for use on Windows; 16 MB of memory for use on
  Windows NT Workstation.
* 20-60 MB of hard disk space required; 46 MB required for
  typical installation, depending on configuration (use the
  Office Upgrade Wizard during Setup to maximize free disk
  space).
* CD-ROM drive (coupon enclosed for 3.5-inch high-density disks;
  CD-ROM contains additional components such as Microsoft
  Internet Explorer, extra clip art, fonts, video files, and
  sounds not available on 3.5-inch disks).
* VGA or higher-resolution video adapter (Super VGA, 256-color
  recommended).
* Microsoft Mouse, Microsoft IntelliMouse, or compatible pointing
  device.

Additional items or services required to use certain features:

* 9600 or higher-baud modem (14,400 baud recommended).
* Multimedia computer required to access sound and other
  multimedia effects.
* Microsoft Exchange Client or Microsoft Outlook required to run
  WordMail. If you use Microsoft Exchange Server, Microsoft
  Exchange Service Pack 3 (SP3) is required.
* 8 MB of additional memory required to run WordMail.
* Some Internet functionality may require Internet access and
  payment of a separate fee to a service provider.


Requirements for Microsoft Word 97 with Windows NT Workstation
       4.0
--------------------------------------------------------------

To use Microsoft Word 97 with Windows NT Workstation 4.0, you
must install Service Pack 2 (SP2) or later.


Using Punctuation Characters in Directory Names May Cause
       Problems
---------------------------------------------------------

If the name of the directory you install Microsoft Office 97,
Microsoft Excel 97, Microsoft Outlook 97, Microsoft PowerPoint
97, or Microsoft Word 97 into includes a comma (,), single
quotation mark ('), or exclamation point (!), you may have
problems when you use the programs. To avoid problems, use the
default directory or use only letters and numbers in directory
names.


Microsoft Plus! Themes Patch
----------------------------

The Themes switcher installed with Microsoft Plus! for Windows 95
is not compatible with the new JPEG graphics filter installed
with Word 97 or Office 97. If you previously installed Themes
from the Plus! Pack for Windows 95, and you installed the JPEG
graphics filter with Word 97 or Office 97, you can upgrade your
existing Themes program by getting the Microsoft Plus! Themes
Patch file from the ValuPack\Patch folder on the Office 97 CD-ROM
or on the network you installed Office from. If you didn't
install Office 97 from a CD-ROM and you have access to the World
Wide Web, point to Microsoft On The Web (Help menu) in any Office
program, and then click Free Stuff.

When you have located the Themes.exe patch file, perform the
following steps to upgrade your existing Themes program.

 1. Locate the folder on your hard disk that contains the program file
    Themes.exe. If you installed Plus! in the default location, then
    the file Themes.exe is located in \Program Files\Plus!.

     - In Windows 95, click the Windows Start button, point to Find,
       and then click Files Or Folders. Search for the file Themes.exe
       on your hard disk.
     - In Windows NT Workstation, click Search on the File menu in File
       Manager, and then search for the file Themes.exe.

 2. Delete the file Themes.exe from your hard disk.
 3. Copy the Themes.exe patch file from the Office 97 CD-ROM (or that
    you downloaded from the Web) to the folder on your hard disk that
    contained the file Themes.exe.

________________________________________________________________
MICROSOFT WORD 97 HELP AND GETTING RESULTS BOOK

Help Topics Graphics Don't Print Clearly
----------------------------------------

When you print a Help topic that contains a graphic, the graphic
may not print clearly. In particular, this occurs when you print
a topic with grayscale colors using a printer driver that does
not have options to control dithering.


Correction to Getting Results Book
----------------------------------

On page 218, "Click Scrolling Text (Format menu)." should be
"Click Scrolling Text (Insert menu)."

________________________________________________________________
WORKING WITH DOCUMENTS

Missing Characters when Opening Macintosh and Multilingual
       Documents
----------------------------------------------------------

When you open a Macintosh or multilingual document, some of the
characters in the document may be missing. This occurs if you
share Macintosh files that use Chicago, Geneva, or Monaco fonts
(these fonts are converted to Arial, Courier New, or Times New
Roman True Type fonts in Windows), or if you share multilingual
files that use Arial, Courier New, or Times New Roman TrueType
fonts, because the character may not be available using this
font. To make sure all of the characters appear in your converted
Macintosh or multilingual documents when the document uses Arial,
Courier New, or Times New Roman fonts, install international
support for Central Europe, Cyrillic, or Greek using the Windows
95 Setup program by performing the following steps:

 1. Click the Windows Start button, point to Settings, and then click
    Control Panel.
 2. Double-click the Add/Remove Programs icon.
 3. Click the Windows Setup tab.
 4. In the Components box, select the Multilanguage Support check box.
 5. Click Details.
 6. In the Components box, select the Central Europe, Cyrillic, or
    Greek check box. Clear the other check boxes to save hard disk
    space.

Note that if you run Windows NT Workstation 3.5 or later, this
problem does not occur because the fonts included in Windows NT
Workstation contain support for international and extended
characters.


Cannot Edit a Word Document Embedded Object in Word 95
------------------------------------------------------

When you insert a Word document as an embedded object in a
document in Word 97, save the document in the Word 6.0/95 format
or Rich Text Format, and then open the document in Word 95, you
may receive the error message "Word cannot edit the object" when
you double-click the object to edit it. This occurs because when
you save the document created in Word 97 in the Word 6.0/95
format or Rich Text Format, the embedded object is not saved as a
Word 95 document object. To edit the object, you must have Word
97 installed on your computer.


Cannot Edit an Embedded Object Created in a Word 95 Document
       After Saving in Word 97
------------------------------------------------------------

If you create an embedded object in a Word 95 document, open the
document in Word 97, and then save the document in Word 6.0/95
format or Rich Text Format, the embedded object is updated to a
later version of the OLE object server program on the computer
running Word 97. If you reopen the document in Word 95 on a
computer that does not have Word 97 or Office 97 installed, you
may not be able to edit the object.

This can occur with any OLE object, including objects created in
Word 97 documents. To see a list of OLE server programs installed
on your computer, view the list in the Object dialog box (Insert
Menu).


Cannot Undo Edit After Attaching a Template
-------------------------------------------

When you attach a different template to the active document, the
Undo command (Edit menu) is not available. This may occur after
running a wizard that attaches a template to the active document.


Mail Merge Errors in Microsoft Word 97 with Comma Separated
       Values or Tab Separated Values Files Exported from
       Microsoft Outlook 97
----------------------------------------------------------

When you export a file from Outlook as Comma Separated Values or
Tab Separated Values to use in a mail merge in Word, use the Map
Custom Fields dialog box in Outlook to select only the fields you
want to export for the mail merge. If you don't use the Map
Custom Fields dialog box, you may get unexpected results in Word.

________________________________________________________________
WORKING WITH E-MAIL

Using WordMail Templates
------------------------

There are six custom e-mail templates and one blank e-mail
template you can use when you select Word as your e-mail editor
in Microsoft Outlook or Microsoft Exchange. (Some Help topics
state that there are ten e-mail templates available.)


Turning Off Word as E-mail Editor in Microsoft Exchange
-------------------------------------------------------

If you do not want to use Word as your e-mail editor in Microsoft
Exchange, do the following in Microsoft Exchange:

 1. On the Compose menu, click WordMail Options.
 2. Clear the Enable Word As E-mail Editor check box.


Vendor Independent Messaging (VIM) Not Supported on Windows NT
       Workstation
--------------------------------------------------------------

If you use a 16-bit e-mail program compatible with Vendor
Independent Messaging (VIM), such as Lotus cc:Mail, on Windows NT
Workstation, you are not able to send or route documents.

________________________________________________________________
MICROSOFT OFFICE 97 VALUPACK

Microsoft Office 97 ValuPack Setup May Not Be Successful Without
       Administrative Permissions
----------------------------------------------------------------

If you use Windows NT Workstation 3.51 or later, you must be a
member of the Administrators group to install some components of
the Office 97 ValuPack.


Microsoft Office 97 Sounds Don't Work with Windows NT Workstation
       3.51
-----------------------------------------------------------------

The Office 97 sounds available in the Microsoft Office 97
ValuPack don't work if you use Windows NT Workstation 3.51, even
if the Provide Feedback With Sound check box is selected on the
General tab in the Options dialog box (Tools menu) in the Office
programs. Note that the sounds available with the Office
Assistant do work with Windows NT Workstation 3.51 if you have
selected the Make Sounds check box on the Options tab in the
Office Assistant dialog box.


Sharing Microsoft Word 97 Files with Earlier Versions of
       Microsoft Word
--------------------------------------------------------
  
The Word 97 file format converter (Wrd97cnv.exe) is available on
the Microsoft Word 97 CD-ROM in the ValuPack\Wrd97cnv folder, in
addition to the locations mentioned in Microsoft Word 97 Help.
For more information about converting Word 97 files, see
Microsoft Word 97 Help.

________________________________________________________________
PRINTING

Solutions for Printing Drawing Objects
--------------------------------------

This section lists workarounds for printer driver and other
printing problems.

HP LaserJet series 4 and 5, Windows 95, Microsoft Universal
Printer Driver: Several output quality problems may occur. These
problems may be corrected by changing the printer settings. Click
the Start button on the Windows taskbar, point to Settings, and
then click Printers. Select the printer you are using. On the
File menu, click Properties. Click the Graphics tab, and then
select the Use Raster Graphics option.

PostScript printing, Windows NT Workstation versions 3.51 and
4.0: Fill effects may not print correctly. The problem may be
fixed by upgrading to the latest version of the Microsoft
PostScript Driver for Windows NT Workstation 3.51 or 4.0.
Download the latest driver from:
ftp://ftp.microsoft.com/bussys/winnt/winnt-
public/fixes/usa/NT351/hotfixes-postSP5/pscript-fix.

PostScript printing, Windows 95, Print To File: With some
PostScript printers, the file may be sent to the printer rather
than to the file. The problem may be fixed by upgrading to the
latest PostScript driver based on Adobe PostScript 4.1.

HP LaserJet 5Si, Windows 95: Shapes and WordArt with some fill
effects may not print correctly. These problems may be corrected
by changing the printer settings. Click the Start button on the
Windows taskbar, point to Settings, and then click Printers.
Select the printer you are using. On the File menu, click
Properties. Click the Print Quality tab. Under Advanced, click
the Settings button, and then select the Raster Graphics And Text
option.

HP DeskJet 1600C, Windows 95: Use driver version 4.2 or later.
Download the latest driver from:
http://www.hp.com/

HP Color LaserJet, Windows 95: Pattern-filled objects may not
print correctly. This problem may be fixed by upgrading the
driver to version 1.300 or later. Download the latest driver
from:
http://www.hp.com

HP Color LaserJet PostScript, Windows 95: Objects with pattern
fills may appear in black and white rather than in color. The
problem may be fixed by upgrading to a driver based on Adobe
PostScript 4.1. You can download the latest driver from:
http://www.hp.com/

Lexmark Optra R and Optra L Series PostScript, Windows NT
Workstation versions 3.51 and 4.0: Gradient-filled objects may
print poorly. Contact the Lexmark Technical Support Center for
assistance.

________________________________________________________________
MICROSOFT VISUAL BASIC FOR APPLICATIONS

Changes to Code Examples
------------------------

Code examples in Microsoft Word Visual Basic Help (VbaWrd8.hlp)
should be changed as follows.


ExitWindows method example -- change the first line to:

Documents.Save NoPrompt:=True,
OriginalFormat:=wdOriginalDocumentFormat


OutsideLineWidth property example -- change fourth line in the
first example to:

OutsideLineWidth = wdLineWidth075pt


SnapToShapes property example -- change the first example to:

Options.SnapToShapes = True


DefaultBorderColorIndex Property Example -- change the example to
read:

ActiveDocument.Paragraphs(1).Borders.Enable = True
With Options
    .DefaultBorderColorIndex = wdRed
    .DefaultBorderLineStyle = wdLineStyleDouble
End With


Hyperlinks property example -- change the second line of the
third example to:

If InStr(LCase(aHyperlink.Address), "microsoft") <> 0 Then


MailMergeDataFields Collection object -- change the first line in
the second example in the topic to:

If ActiveDocument.MailMerge.DataSource.Type = wdMergeInfoFromWord
Then


MailMergeFieldNames Collection object -- change the first line in
the second example in the topic to:

If ActiveDocument.MailMerge.DataSource.Type = wdMergeInfoFromWord
Then


SpellingSuggestion object -- change the second line in the first
example in the topic to:

MsgBox
ActiveDocument.Words(1).GetSpellingSuggestions.Item(1).Name


RevisedPropertiesMark property example -- change second example
to:

temp = Options.RevisedPropertiesMark


Dictionary object -- change the first line of the last example in
the topic to:

Set myspell = Languages(wdEnglishUS).ActiveSpellingDictionary


Uniform property example -- change the third line in the first
example to:

myTable.Cell(3, 3).Split 1,2


Indexes property example -- the second example is not valid and
will not work.


ChapterPageSeparator property example and HeadingLevelForChapter
property example -- change both examples to read:

Documents.Add
For i = 1 To 5
    With Selection
        .TypeParagraph
        .InsertBreak
    End With
Next i
ActiveDocument.Content.Style = wdStyleHeading1
ActiveDocument.Content.ListFormat.ApplyListTemplate _

ListTemplate:=ListGalleries(wdOutlineNumberGallery).ListTemplates
(7)

Set myHead =
ActiveDocument.Sections(1).Headers(wdHeaderFooterPrimary)
With myHead.PageNumbers
    .Add PageNumberAlignment:=wdAlignPageNumberCenter
    .NumberStyle = wdPageNumberStyleArabic
    .IncludeChapterNumber = True
    .HeadingLevelForChapter = 0
    .ChapterPageSeparator = wdSeparatorEnDash
End With


SaveAs method -- third example should be replaced with:

This example retrieves the SaveFormat property value for the
WordPerfect 5.x for Windows converter, and then it uses this
value with the SaveAs method.

For Each cnv In Application.FileConverters
    If cnv.ClassName = "WrdPrfctWin" Then
        ActiveDocument.SaveAs FileName:="MyWP.doc",
FileFormat:=cnv.SaveFormat
    End If
Next cnv


Points property example and SetPosition method -- example should
be changed to:

Set myDocument = ActiveDocument
With myDocument.Shapes(3).Nodes
    pointsArray = .Item(2).Points
    currXvalue = pointsArray(1, 1)
    currYvalue = pointsArray(1, 2)
    .SetPosition 2, currXvalue + 200, currYvalue + 300
End With


InsertSymbol Method Has a Fourth Argument
-----------------------------------------

The InsertSymbol method has the following fourth argument, Bias
Optional Variant. Sets the font bias for symbols. This argument
is useful for setting the correct font bias for characters in Far
East versions of Word. Can be one of the following WdFontBias
constants: wdFontBiasDefault, wdFontBiasDontCare, or
wdFontBiasFareast.


RevisedLinesColor Property
--------------------------

The RevisedLinesColor property has a constant that is not valid:
wdByAuthor.


Reload Method Not Available
---------------------------

When you use the Reload method in a Microsoft Visual Basic for
Applications macro in Microsoft Word 97, the macro may start to
run before the reload is completed. You may want to avoid using
the Reload method in Word.


MsgBox Function
---------------

In addition to the constants listed for the MsgBox function, the
following constants are available for use as button argument
settings.

Constant            Value               Description
----------------------------------------------------------------
vbHelp              16384 (&H4000)      Adds a Help button to
                                        the message box. Click
                                        the Help button or press
                                        F1 to generate a Help
                                        event.

vbSetForeground     65536 (&H10000)     Places the message box
                                        in the foreground and
                                        activates it. Keyboard
                                        input is directed to the
                                        message box.
                                        
vbRight             524288 (&H80000)    Right-justifies the text
                                        in the message box.
                                        
vbRtlReading        1048576 (&H100000)  On Hebrew and Arabic
                                        systems, shows
                                        message and caption text
                                        using right-to-left
                                        reading order.


ReSize Event
------------

The syntax and remarks for the Resize event should read as
follows:

Syntax: Private Sub UserForm_Resize()

Remarks: Use a Resize event procedure to move or resize controls
when the parent UserForm is resized. You can also use this event
procedure to recalculate variables or properties.

Note: UserForm controls have no Resize event.

________________________________________________________________
MICROSOFT FORMS 2.0: ISSUES AND DOCUMENTATION CHANGES

The following sections describe changes to the documentation for
Microsoft Forms 2.0. These changes supercede the contents of the
Help file Fm20.hlp. These sections also contain known issues with
Microsoft Forms 2.0.


Methods
-------

* Repaint Method: The Repaint method does not return a value. The
  correct syntax is:

     Object.Repaint


Controls
--------

* CheckBox Control: The initial value of a CheckBox control is
  False.

  The GroupName property can be used with one or more CheckBox
  controls. Note, however, that the CheckBox controls in a group
  still operate independently of one another.

* OptionButton Control: The initial value of an OptionButton
  control is False.

* ToggleButton Control: The initial value of a ToggleButton
  control is False.


Events
------

* Click Event: When the user clicks on the active page or tab of
  a MultiPage or the active tab of a TabStrip, the Click event
  is initiated. However, if the MultiPage or TabStrip contains
  multiple rows of page tabs, the Click event is only initiated
  for tabs in the foremost row of pages.


Properties
----------

* AutoTab Property: When this property is True, the
TabKeyBehavior property is not in effect.

* AutoSize Property: Setting the AutoSize property to True
  adjusts the size of a control to fit the text within it.  If
  you change the text in a control after setting AutoSize to
  True, you must also set AutoSize to False and then back to
  True to get the control to resize.

* DragBehavior Property: fmDragBehaviorEnabled should not be used
  with MatchRequired = True.

* IMEMode Property: The following is a more detailed description
  of the IMEMode property.

     IMEMode     Meaning
     ----------  --------------------------------------------
     NoControl        The control does not affect the IME.
     On               Activates the IME without changing its
                      language or other settings.
     Off              Turns the IME off without affecting the
                      language or other settings.  In China,
                      Off also switches the keyboard to non-IME.
     Disabled         Makes the IME disappear so that its settings
                      cannot be changed.

  All other values set the IME to a particular language.

  Controls, such as command buttons, that do not allow typing
  will disable the IME while they have focus.

  Every control makes a copy of the IME state in effect when
  that control receives focus. When it loses focus, it restores
  this saved state.  This saving and restoring occurs without
  regard to the value of the IMEMode property of the control.
  This differs slightly from the example in the Help text.

  Each change that a user makes to the IME while a control has
  focus immediately updates that control's IMEMode property (if
  it has one).

  All controls will accept setting all IME modes without error,
  but when a mode is not "native" to a locale it will:
     a. Not be listed in property sheets in that locale.
     b. Have the same effect as a native mode.  See below.

  All modes are native, except:

     - Disabled is native only in Japan. Elsewhere, it acts like Off.
     
     - In Japan, the Hangul and Hanzi modes are not native. Using them
       has the same effect as using Hiragana.
     
     - In Korea, the only native modes are NoControl, Hanzi, and Alpha
       (Full and Half). Off and Disabled have the same effect as Alpha.
       On, Hiragana, Katakana, and Hanzi have the same effect as
       Hangul.
     
     - In China, the Hiragana, Katakana, Hangul, and Hanzi modes are
       not native. Using them has the same effect as HanziFull or Hanzi
       as appropriate.
     
     - Everywhere else, the only native mode is "NoControl."  All other
       modes have the effect of "NoControl."

* List Property: The last sentence of the Help text is not
  correct. You can use the List property to copy an entire
  single dimension or multidimensional array of values to a
  control.

* ListRows Property: Setting ListRows to 0 shows all the rows in
  the list.

* MatchRequired Property: This property is in effect when the
  MatchEntry property is set to fmMatchEntryComplete or
  fmMatchEntryFirstLetter, but is not enforced when MatchEntry
  is set to fmMatchEntryNone.

  When the Input Method Editor (IME) is used to process
  keystrokes, the MatchRequired property does not always ensure
  that the user types a matching value in a ComboBox.

* MultiLine Property: When this property is True, the
  TabKeyBehavior property is not in effect.

* ScrollBars Property: Corrections to text are below.

     - For a single-line control, replace Rule 2 with the following
       sentence: "When the ScrollBars property is set to
       fmScrollBarsHorizontal or fmScrollBarsBoth, the control shows a
       horizontal scroll bar if the text is longer than the edit
       region.  The height of the control will not be changed, so the
       horizontal scroll bar may overlap the text in the control."

     - Ignore Rule 3.

     - For a MultiLine control, ignore the third bulleted item in Rule
       4.

* ShowDropButtonWhen Property: If AutoSize is True, changing the
  ShowDropButtonWhen property immediately changes the size of
  the control based on whether the drop button is visible or
  hidden.

* SpecialEffect Property: This property does not apply to the
  ToggleButton.

* TabKeyBehavior Property: This property is enforced when AutoTab
  is False and MultiLine is True.

* Value Property: The Value property of the TabStrip is an
  integer indicating the active tab. Zero indicates the first
  tab. The maximum value is one less than the number of tabs.

* Visible Property: You are not allowed to change the Visible
  property of a control during the Layout event or Enter event.
  Doing so will cause an   error at run time.


Other Known Issues
------------------

The Marquee control included with Microsoft Internet Explorer 3.0
does not work properly in Microsoft Forms 2.0.  This is a known
problem that will be fixed in a future release of Internet
Explorer.

Calling "Unload Me" during the Enter event of a Microsoft Forms
2.0 CommandButton, OptionButton, or CheckBox may result in an
"Out of stack space" error or may cause an "illegal operation"
error. The workaround is to call "Unload Me" during the Click
event instead.