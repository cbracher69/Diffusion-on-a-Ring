%!PS-Adobe-3.0 EPSF-3.0
%%Creator: Mayura Draw, Version 4.1
%%Title: 5in19eq.md
%%CreationDate: Tue Oct 21 16:08:57 2003
%%BoundingBox: 16 -1 489 352
%%DocumentFonts: ArialMT
%%Orientation: Portrait
%%EndComments
%%BeginProlog
%%BeginResource: procset MayuraDraw_ops
%%Version: 4.1
%%Copyright: (c) 1993-2001 Mayura Software
/PDXDict 100 dict def
PDXDict begin
% width height matrix proc key cache
% definepattern -\> font
/definepattern { %def
  7 dict begin
    /FontDict 9 dict def
    FontDict begin
      /cache exch def
      /key exch def
      /proc exch cvx def
      /mtx exch matrix invertmatrix def
      /height exch def
      /width exch def
      /ctm matrix currentmatrix def
      /ptm matrix identmatrix def
      /str
      (xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx)
      def
    end
    /FontBBox [ %def
      0 0 FontDict /width get
      FontDict /height get
    ] def
    /FontMatrix FontDict /mtx get def
    /Encoding StandardEncoding def
    /FontType 3 def
    /BuildChar { %def
      pop begin
      FontDict begin
        width 0 cache { %ifelse
          0 0 width height setcachedevice
        }{ %else
          setcharwidth
        } ifelse
        0 0 moveto width 0 lineto
        width height lineto 0 height lineto
        closepath clip newpath
        gsave proc grestore
      end end
    } def
    FontDict /key get currentdict definefont
  end
} bind def

% dict patternpath -
% dict matrix patternpath -
/patternpath { %def
  dup type /dicttype eq { %ifelse
    begin FontDict /ctm get setmatrix
  }{ %else
    exch begin FontDict /ctm get setmatrix
    concat
  } ifelse
  currentdict setfont
  FontDict begin
    FontMatrix concat
    width 0 dtransform
    round width div exch round width div exch
    0 height dtransform
    round height div exch
    round height div exch
    0 0 transform round exch round exch
    ptm astore setmatrix

    pathbbox
    height div ceiling height mul 4 1 roll
    width div ceiling width mul 4 1 roll
    height div floor height mul 4 1 roll
    width div floor width mul 4 1 roll

    2 index sub height div ceiling cvi exch
    3 index sub width div ceiling cvi exch
    4 2 roll moveto

    FontMatrix ptm invertmatrix pop
    { %repeat
      gsave
        ptm concat
        dup str length idiv { %repeat
          str show
        } repeat
        dup str length mod str exch
        0 exch getinterval show
      grestore
      0 height rmoveto
    } repeat
    pop
  end end
} bind def

% dict patternfill -
% dict matrix patternfill -
/patternfill { %def
  gsave
    eoclip patternpath
  grestore
  newpath
} bind def

/img { %def
  gsave
  /imgh exch def
  /imgw exch def
  concat
  imgw imgh 8
  [imgw 0 0 imgh neg 0 imgh]
  /colorstr 768 string def
  /colorimage where {
    pop
    { currentfile colorstr readhexstring pop }
    false 3 colorimage
  }{
    /graystr 256 string def
    {
      currentfile colorstr readhexstring pop
      length 3 idiv
      dup 1 sub 0 1 3 -1 roll
      {
        graystr exch
        colorstr 1 index 3 mul get 30 mul
        colorstr 2 index 3 mul 1 add get 59 mul
        colorstr 3 index 3 mul 2 add get 11 mul
        add add 100 idiv
        put
      } for
      graystr 0 3 -1 roll getinterval
    } image
  } ifelse
  grestore
} bind def

/arrowhead {
  gsave
    [] 0 setdash
    strokeC strokeM strokeY strokeK setcmykcolor
    2 copy moveto
    4 2 roll exch 4 -1 roll exch
    sub 3 1 roll sub
    exch atan rotate dup scale
    arrowtype
    dup 0 eq {
      -1 2 rlineto 7 -2 rlineto -7 -2 rlineto
      closepath fill
    } if
    dup 1 eq {
      0 3 rlineto 9 -3 rlineto -9 -3 rlineto
      closepath fill
    } if
    dup 2 eq {
      -6 -6 rmoveto 6 6 rlineto -6 6 rlineto
      -1.4142 -1.4142 rlineto 4.5858 -4.5858 rlineto
      -4.5858 -4.5858 rlineto closepath fill
    } if
    dup 3 eq {
      -6 0 rmoveto -1 2 rlineto 7 -2 rlineto -7 -2 rlineto
      closepath fill
    } if
    dup 4 eq {
      -9 0 rmoveto 0 3 rlineto 9 -3 rlineto -9 -3 rlineto
      closepath fill
    } if
    dup 5 eq {
      currentpoint newpath 3 0 360 arc
      closepath fill
    } if
    dup 6 eq {
      2.5 2.5 rmoveto 0 -5 rlineto -5 0 rlineto 0 5 rlineto
      closepath fill
    } if
    pop
  grestore
} bind def

/setcmykcolor where { %ifelse
  pop
}{ %else
  /setcmykcolor {
     /black exch def /yellow exch def
     /magenta exch def /cyan exch def
     cyan black add dup 1 gt { pop 1 } if 1 exch sub
     magenta black add dup 1 gt { pop 1 } if 1 exch sub
     yellow black add dup 1 gt { pop 1 } if 1 exch sub
     setrgbcolor
  } bind def
} ifelse

/RE { %def
  findfont begin
  currentdict dup length dict begin
    { %forall
      1 index /FID ne { def } { pop pop } ifelse
    } forall
    /FontName exch def dup length 0 ne { %if
      /Encoding Encoding 256 array copy def
      0 exch { %forall
        dup type /nametype eq { %ifelse
          Encoding 2 index 2 index put
          pop 1 add
        }{ %else
          exch pop
        } ifelse
      } forall
    } if pop
  currentdict dup end end
  /FontName get exch definefont pop
} bind def

/spacecount { %def
  0 exch
  ( ) { %loop
    search { %ifelse
      pop 3 -1 roll 1 add 3 1 roll
    }{ pop exit } ifelse
  } loop
} bind def

/WinAnsiEncoding [
  39/quotesingle 96/grave 130/quotesinglbase/florin/quotedblbase
  /ellipsis/dagger/daggerdbl/circumflex/perthousand
  /Scaron/guilsinglleft/OE 145/quoteleft/quoteright
  /quotedblleft/quotedblright/bullet/endash/emdash
  /tilde/trademark/scaron/guilsinglright/oe/dotlessi
  159/Ydieresis 164/currency 166/brokenbar 168/dieresis/copyright
  /ordfeminine 172/logicalnot 174/registered/macron/ring
  177/plusminus/twosuperior/threesuperior/acute/mu
  183/periodcentered/cedilla/onesuperior/ordmasculine
  188/onequarter/onehalf/threequarters 192/Agrave/Aacute
  /Acircumflex/Atilde/Adieresis/Aring/AE/Ccedilla
  /Egrave/Eacute/Ecircumflex/Edieresis/Igrave/Iacute
  /Icircumflex/Idieresis/Eth/Ntilde/Ograve/Oacute
  /Ocircumflex/Otilde/Odieresis/multiply/Oslash
  /Ugrave/Uacute/Ucircumflex/Udieresis/Yacute/Thorn
  /germandbls/agrave/aacute/acircumflex/atilde/adieresis
  /aring/ae/ccedilla/egrave/eacute/ecircumflex
  /edieresis/igrave/iacute/icircumflex/idieresis
  /eth/ntilde/ograve/oacute/ocircumflex/otilde
  /odieresis/divide/oslash/ugrave/uacute/ucircumflex
  /udieresis/yacute/thorn/ydieresis
] def

/SymbolEncoding [
  32/space/exclam/universal/numbersign/existential/percent
  /ampersand/suchthat/parenleft/parenright/asteriskmath/plus
  /comma/minus/period/slash/zero/one/two/three/four/five/six
  /seven/eight/nine/colon/semicolon/less/equal/greater/question
  /congruent/Alpha/Beta/Chi/Delta/Epsilon/Phi/Gamma/Eta/Iota
  /theta1/Kappa/Lambda/Mu/Nu/Omicron/Pi/Theta/Rho/Sigma/Tau
  /Upsilon/sigma1/Omega/Xi/Psi/Zeta/bracketleft/therefore
  /bracketright/perpendicular/underscore/radicalex/alpha
  /beta/chi/delta/epsilon/phi/gamma/eta/iota/phi1/kappa/lambda
  /mu/nu/omicron/pi/theta/rho/sigma/tau/upsilon/omega1/omega
  /xi/psi/zeta/braceleft/bar/braceright/similar
  161/Upsilon1/minute/lessequal/fraction/infinity/florin/club
  /diamond/heart/spade/arrowboth/arrowleft/arrowup/arrowright
  /arrowdown/degree/plusminus/second/greaterequal/multiply
  /proportional/partialdiff/bullet/divide/notequal/equivalence
  /approxequal/ellipsis/arrowvertex/arrowhorizex/carriagereturn
  /aleph/Ifraktur/Rfraktur/weierstrass/circlemultiply
  /circleplus/emptyset/intersection/union/propersuperset
  /reflexsuperset/notsubset/propersubset/reflexsubset/element
  /notelement/angle/gradient/registerserif/copyrightserif
  /trademarkserif/product/radical/dotmath/logicalnot/logicaland
  /logicalor/arrowdblboth/arrowdblleft/arrowdblup/arrowdblright
  /arrowdbldown/lozenge/angleleft/registersans/copyrightsans
  /trademarksans/summation/parenlefttp/parenleftex/parenleftbt
  /bracketlefttp/bracketleftex/bracketleftbt/bracelefttp
  /braceleftmid/braceleftbt/braceex
  241/angleright/integral/integraltp/integralex/integralbt
  /parenrighttp/parenrightex/parenrightbt/bracketrighttp
  /bracketrightex/bracketrightbt/bracerighttp/bracerightmid
  /bracerightbt
] def

/patarray [
/leftdiagonal /rightdiagonal /crossdiagonal /horizontal
/vertical /crosshatch /fishscale /wave /brick
] def
/arrowtype 0 def
/fillC 0 def /fillM 0 def /fillY 0 def /fillK 0 def
/strokeC 0 def /strokeM 0 def /strokeY 0 def /strokeK 1 def
/pattern -1 def
/mat matrix def
/mat2 matrix def
/nesting 0 def
/deferred /N def
/c /curveto load def
/c2 { pop pop c } bind def
/C /curveto load def
/C2 { pop pop C } bind def
/e { gsave concat 0 0 moveto } bind def
/F {
  nesting 0 eq { %ifelse
    pattern -1 eq { %ifelse
      fillC fillM fillY fillK setcmykcolor eofill
    }{ %else
      gsave fillC fillM fillY fillK setcmykcolor eofill grestore
      0 0 0 1 setcmykcolor
      patarray pattern get findfont patternfill
    } ifelse
  }{ %else
    /deferred /F def
  } ifelse
} bind def
/f { closepath F } bind def
/K { /strokeK exch def /strokeY exch def
     /strokeM exch def /strokeC exch def } bind def
/k { /fillK exch def /fillY exch def
     /fillM exch def /fillC exch def } bind def
/opc { pop } bind def
/Opc { pop } bind def
/L /lineto load def
/L2 { pop pop L } bind def
/m /moveto load def
/m2 { pop pop m } bind def
/n /newpath load def
/N {
  nesting 0 eq { %ifelse
    newpath
  }{ %else
    /deferred /N def
  } ifelse
} def
/S {
  nesting 0 eq { %ifelse
    strokeC strokeM strokeY strokeK setcmykcolor stroke
  }{ %else
    /deferred /S def
  } ifelse
} bind def
/s { closepath S } bind def
/Tx { fillC fillM fillY fillK setcmykcolor show
      0 leading neg translate 0 0 moveto } bind def
/T { grestore } bind def
/TX { pop } bind def
/Ts { pop } bind def
/tal { pop } bind def
/tld { pop } bind def
/tbx { pop exch pop sub /jwidth exch def } def
/tpt { %def
  fillC fillM fillY fillK setcmykcolor
  moveto show
} bind def
/tpj { %def
  fillC fillM fillY fillK setcmykcolor
  moveto
  dup stringwidth pop
  3 -1 roll
  exch sub
  1 index spacecount
  dup 0 eq { %ifelse
    pop pop show
  }{ %else
    div 0 8#040 4 -1 roll widthshow
  } ifelse
} bind def
/u {} def
/U {} def
/*u { /nesting nesting 1 add def } def
/*U {
  /nesting nesting 1 sub def
  nesting 0 eq {
    deferred cvx exec
  } if
} def
/w /setlinewidth load def
/d /setdash load def
/B {
  nesting 0 eq { %ifelse
    gsave F grestore S
  }{ %else
    /deferred /B def
  } ifelse
} bind def
/b { closepath B } bind def
/z { /align exch def pop /leading exch def exch findfont
     exch scalefont setfont } bind def
/tfn { exch findfont
     exch scalefont setfont } bind def
/Pat { /pattern exch def } bind def
/cm { 6 array astore concat } bind def
/q { mat2 currentmatrix pop } bind def
/Q { mat2 setmatrix } bind def
/Ah {
  pop /arrowtype exch def
  currentlinewidth 5 1 roll arrowhead
} bind def
/Arc {
  mat currentmatrix pop
    translate scale 0 0 1 5 -2 roll arc
  mat setmatrix
} bind def
/Arc2 { pop pop Arc } bind def
/Bx {
  mat currentmatrix pop
    concat /y1 exch def /x1 exch def /y2 exch def /x2 exch def
    x1 y1 moveto x1 y2 lineto x2 y2 lineto x2 y1 lineto
  mat setmatrix
} bind def
/Rr {
  mat currentmatrix pop
    concat /yrad exch def /xrad exch def
    2 copy gt { exch } if /x2 exch def /x1 exch def
    2 copy gt { exch } if /y2 exch def /y1 exch def
    x1 xrad add y2 moveto
    matrix currentmatrix x1 xrad add y2 yrad sub translate xrad yrad scale
    0 0 1 90 -180 arc setmatrix
    matrix currentmatrix x1 xrad add y1 yrad add translate xrad yrad scale
    0 0 1 180 270 arc setmatrix
    matrix currentmatrix x2 xrad sub y1 yrad add translate xrad yrad scale
    0 0 1 270 0 arc setmatrix
    matrix currentmatrix x2 xrad sub y2 yrad sub translate xrad yrad scale
    0 0 1 0 90 arc setmatrix
    closepath
  mat setmatrix
} bind def
/Ov {
  mat currentmatrix pop
    concat translate scale 1 0 moveto 0 0 1 0 360 arc closepath
  mat setmatrix
} bind def
end
%%EndResource
%%EndProlog
%%BeginSetup
%PDX g 3 3 0 0
%%IncludeFont: ArialMT
PDXDict begin
%%EndSetup
%%Page: 1 1
%%BeginPageSetup
/_PDX_savepage save def

15 15 [300 72 div 0 0 300 72 div 0 0]
{ %definepattern
  2 setlinecap
  7.5 0 moveto 15 7.5 lineto
  0 7.5 moveto 7.5 15 lineto
  2 setlinewidth stroke
} bind
/rightdiagonal true definepattern pop

15 15 [300 72 div 0 0 300 72 div 0 0]
{ %definepattern
  2 setlinecap
  7.5 0 moveto 0 7.5 lineto
  15 7.5 moveto 7.5 15 lineto
  2 setlinewidth stroke
} bind
/leftdiagonal true definepattern pop

15 15 [300 72 div 0 0 300 72 div 0 0]
{ %definepattern
  2 setlinecap
  0 7.5 moveto 15 7.5 lineto
  2 setlinewidth stroke
} bind
/horizontal true definepattern pop

15 15 [300 72 div 0 0 300 72 div 0 0]
{ %definepattern
  2 setlinecap
  7.5 0 moveto 7.5 15 lineto
  2 setlinewidth stroke
} bind
/vertical true definepattern pop

15 15 [300 72 div 0 0 300 72 div 0 0]
{ %definepattern
  2 setlinecap
  0 7.5 moveto 15 7.5 lineto
  7.5 0 moveto 7.5 15 lineto
  2 setlinewidth stroke
} bind
/crosshatch true definepattern pop

30 30 [300 72 div 0 0 300 72 div 0 0]
{ %definepattern
  2 setlinecap
  0 7.5 moveto 30 7.5 lineto
  0 22.5 moveto 30 22.5 lineto
  7.5 0 moveto 7.5 7.5 lineto
  7.5 22.5 moveto 7.5 30 lineto
  22.5 7.5 moveto 22.5 22.5 lineto
  1 setlinewidth stroke
} bind
/brick true definepattern pop

30 30 [300 72 div 0 0 300 72 div 0 0]
{ %definepattern
  2 2 scale
  2 setlinecap
  7.5 0 moveto 15 7.5 lineto
  0 7.5 moveto 7.5 15 lineto
  7.5 0 moveto 0 7.5 lineto
  15 7.5 moveto 7.5 15 lineto
  0.5 setlinewidth stroke
} bind
/crossdiagonal true definepattern pop

30 30 [300 72 div 0 0 300 72 div 0 0]
{ %definepattern
  2 2 scale
  1 setlinecap
  0 7.5 moveto 0 15 7.5 270 360 arc
  7.5 15 moveto 15 15 7.5 180 270 arc
  0 7.5 moveto 7.5 7.5 7.5 180 360 arc
  0.5 setlinewidth stroke
} bind
/fishscale true definepattern pop

30 30 [300 72 div 0 0 300 72 div 0 0]
{ %definepattern
  1 setlinecap 0.5 setlinewidth
  7.5 0 10.6 135 45 arcn
  22.5 15 10.6 225 315 arc
  stroke
  7.5 15 10.6 135 45 arcn
  22.5 30 10.6 225 315 arc
  stroke
} bind
/wave true definepattern pop

WinAnsiEncoding /_ArialMT /ArialMT RE

newpath 2 setlinecap 0 setlinejoin 2 setmiterlimit
[] 0 setdash
16 -1 moveto 16 352 lineto 489 352 lineto 489 -1 lineto closepath clip
newpath
%%EndPageSetup
0.25098 0.25098 0.25098 0 K
0.75 w
[3 3] 0 d
q
1 0 0 1 0 0 cm
81 117.7 m
81 117.7 L
84.9 117.7 L
88.8 117.7 L
92.7 117.7 L
96.5 117.7 L
100.4 117.7 L
104.3 117.7 L
108.2 117.7 L
112.1 117.7 L
116 117.7 L
119.8 117.7 L
123.7 117.7 L
127.6 117.7 L
131.5 117.7 L
135.4 117.7 L
139.3 117.7 L
143.1 117.7 L
147 117.7 L
150.9 117.7 L
154.8 117.7 L
158.7 117.7 L
162.6 117.7 L
166.4 117.7 L
170.3 117.7 L
174.2 117.7 L
178.1 117.7 L
182 117.7 L
185.9 117.7 L
189.8 117.7 L
193.6 117.7 L
197.5 117.7 L
201.4 117.7 L
205.3 117.7 L
209.2 117.7 L
213.1 117.7 L
216.9 117.7 L
220.8 117.7 L
224.7 117.7 L
228.6 117.7 L
232.5 117.7 L
236.4 117.7 L
240.2 117.7 L
244.1 117.7 L
248 117.7 L
251.9 117.7 L
255.8 117.7 L
259.7 117.7 L
263.5 117.7 L
267.4 117.7 L
271.3 117.7 L
275.2 117.7 L
279.1 117.7 L
283 117.7 L
286.9 117.7 L
290.7 117.7 L
294.6 117.7 L
298.5 117.7 L
302.4 117.7 L
306.3 117.7 L
310.2 117.7 L
314 117.7 L
317.9 117.7 L
321.8 117.7 L
325.7 117.7 L
329.6 117.7 L
333.5 117.7 L
337.3 117.7 L
341.2 117.7 L
345.1 117.7 L
349 117.7 L
352.9 117.7 L
356.8 117.7 L
360.6 117.7 L
364.5 117.7 L
368.4 117.7 L
372.3 117.7 L
376.2 117.7 L
380.1 117.7 L
384 117.7 L
387.8 117.7 L
391.7 117.7 L
395.6 117.7 L
399.5 117.7 L
403.4 117.7 L
407.3 117.7 L
411.1 117.7 L
415 117.7 L
418.9 117.7 L
422.8 117.7 L
426.7 117.7 L
430.6 117.7 L
434.4 117.7 L
438.3 117.7 L
442.2 117.7 L
446.1 117.7 L
450 117.7 L
453.9 117.7 L
457.7 117.7 L
461.6 117.7 L
465.5 117.7 L
469.4 117.7 L
Q
S
u
0.25 w
[] 0 d
216.488 139.506 107.469 248.525 [1 0 0 1 -12.48 -0.8322] Bx
b
u
u
0.5 w
25.9175 25.9175 168.223 433.316 [1.33 0 0 1.33 -74.24 -383.1] Ov
s
37.0753 37.0753 136.128 459.096 [1.33 0 0 1.33 -31.56 -417.4] Ov
s
U
u
0.498039 0.498039 0.498039 0 k
1 1 1 0 K
4.55901 4.55901 211.892 454.361 [1.33 0 0 1.33 -132.6 -369.3] Ov
b
4.55901 4.55901 211.892 454.361 [1.258 0.4319 -0.4319 1.258 65.49 -430.5] Ov
b
4.55901 4.55901 211.892 454.361 [1.049 0.817 -0.817 1.049 272.6 -423.8] Ov
b
4.55901 4.55901 211.892 454.361 [1.05 -0.8168 0.8168 1.05 -418.3 -77.39] Ov
b
4.55901 4.55901 211.892 454.361 [1.258 -0.4317 0.4317 1.258 -299.6 -247.3] Ov
b
U
u
0.121569 0.121569 0.121569 0 k
4.55901 4.55901 211.892 454.361 [0.7273 1.114 -1.114 0.7273 466.5 -350.4] Ov
b
4.55901 4.55901 211.892 454.361 [0.3265 1.289 -1.289 0.3265 625.5 -218.2] Ov
b
4.55901 4.55901 211.892 454.361 [-0.1099 1.325 -1.325 -0.1099 733.4 -41.25] Ov
b
4.55901 4.55901 211.892 454.361 [-0.5344 1.218 -1.218 -0.5344 777.8 161.2] Ov
b
4.55901 4.55901 211.892 454.361 [-0.9009 0.9784 -0.9784 -0.9009 754.3 367.1] Ov
b
4.55901 4.55901 211.892 454.361 [-1.17 0.633 -0.633 -1.17 665.2 553.6] Ov
b
4.55901 4.55901 211.892 454.361 [-1.312 0.2188 -0.2188 -1.312 520.2 701.7] Ov
b
4.55901 4.55901 211.892 454.361 [-1.312 -0.2191 0.2191 -1.312 334.8 794.4] Ov
b
4.55901 4.55901 211.892 454.361 [-1.17 -0.6332 0.6332 -1.17 129.4 822.1] Ov
b
4.55901 4.55901 211.892 454.361 [-0.9008 -0.9785 0.9785 -0.9008 -73.19 781.5] Ov
b
4.55901 4.55901 211.892 454.361 [-0.5342 -1.218 1.218 -0.5342 -252.3 677.5] Ov
b
4.55901 4.55901 211.892 454.361 [-0.1097 -1.325 1.325 -0.1097 -387.7 520.6] Ov
b
4.55901 4.55901 211.892 454.361 [0.3267 -1.289 1.289 0.3267 -465 328.2] Ov
b
4.55901 4.55901 211.892 454.361 [0.7275 -1.113 1.113 0.7275 -475.7 121.7] Ov
b
U
u
-1.42109e-016 -1.42109e-016 -1.42109e-016 0 k
0.0862745 0.0862745 0.0862745 0 K
0.25 w
q
1.33 0 0 1.33 -41.89 -411.3 cm
143.697 486.013 m
143.697 454.652 L
Q
N
q
1.258 0.4319 -0.4319 1.258 164.9 -440.7 cm
143.697 486.013 m
143.697 454.652 L
Q
N
q
1.049 0.817 -0.817 1.049 369.9 -401.2 cm
143.697 486.013 m
143.697 454.652 L
Q
N
q
0.7273 1.114 -1.114 0.7273 551.2 -297.5 cm
143.697 486.013 m
143.697 454.652 L
Q
N
q
0.3265 1.289 -1.289 0.3265 688.5 -140.6 cm
143.697 486.013 m
143.697 454.652 L
Q
N
q
-0.1099 1.325 -1.325 -0.1099 767.8 52.58 cm
143.697 486.013 m
143.697 454.652 L
Q
N
q
-0.5344 1.218 -1.218 -0.5344 779.8 261.1 cm
143.697 486.013 m
143.697 454.652 L
Q
N
q
-0.9009 0.9784 -0.9784 -0.9009 723.7 462.2 cm
143.697 486.013 m
143.697 454.652 L
Q
N
31.5318 31.5318 123.435 479.494 [1.33 0 0 1.33 -14.67 -444.5] Ov
n
[1.33 0 0 1.33 -49.15 -412.9] e
147.749 459.585 147.749 459.585 tbx
0 tal
7 tld
/_ArialMT 6 tfn
(x) 147.749 454.155 tpt
T
q
-1.17 0.633 -0.633 -1.17 605.5 633.7 cm
143.697 486.013 m
143.697 454.652 L
Q
N
q
-1.312 0.2188 -0.2188 -1.312 437.6 758 cm
143.697 486.013 m
143.697 454.652 L
Q
N
q
-1.312 -0.2191 0.2191 -1.312 238.5 820.9 cm
143.697 486.013 m
143.697 454.652 L
Q
N
q
-1.17 -0.6332 0.6332 -1.17 29.7 815.9 cm
143.697 486.013 m
143.697 454.652 L
Q
N
q
-0.9008 -0.9785 0.9785 -0.9008 -165.5 743.3 cm
143.697 486.013 m
143.697 454.652 L
Q
N
q
-0.5342 -1.218 1.218 -0.5342 -327.2 611.3 cm
143.697 486.013 m
143.697 454.652 L
Q
N
q
-0.1097 -1.325 1.325 -0.1097 -437 433.7 cm
143.697 486.013 m
143.697 454.652 L
Q
N
q
0.3267 -1.289 1.289 0.3267 -483.4 230 cm
143.697 486.013 m
143.697 454.652 L
Q
N
q
0.7275 -1.113 1.113 0.7275 -461.2 22.87 cm
143.697 486.013 m
143.697 454.652 L
Q
N
q
1.05 -0.8168 0.8168 1.05 -372.6 -166.2 cm
143.697 486.013 m
143.697 454.652 L
Q
N
q
1.258 -0.4317 0.4317 1.258 -227.5 -316.4 cm
143.697 486.013 m
143.697 454.652 L
Q
N
U
[1.33 0 0 1.33 39.85 -401.7] e
80.4308 482.601 80.4308 482.601 tbx
0 tal
8 tld
/_ArialMT 7 tfn
(0) 80.4308 476.266 tpt
T
[1.33 0 0 1.33 -43.81 -406.3] e
153.633 484.268 153.633 484.268 tbx
0 tal
8 tld
/_ArialMT 7 tfn
(1) 153.633 477.933 tpt
T
[1.33 0 0 1.33 -43.6 -406.5] e
162.727 479.722 162.727 479.722 tbx
0 tal
8 tld
/_ArialMT 7 tfn
(2) 162.727 473.387 tpt
T
[1.33 0 0 1.33 -44.41 -407.3] e
131.354 484.874 131.354 484.874 tbx
0 tal
8 tld
/_ArialMT 7 tfn
(18) 131.354 478.539 tpt
T
[1.33 0 0 1.33 -45.02 -407.5] e
122.867 480.025 122.867 480.025 tbx
0 tal
8 tld
/_ArialMT 7 tfn
(17) 122.867 473.69 tpt
T
[1.33 0 0 1.33 -43.81 -407.5] e
169.698 472.901 169.698 472.901 tbx
0 tal
8 tld
1 1 1 0 k
/_ArialMT 7 tfn
(3) 169.698 466.566 tpt
T
[1.33 0 0 1.33 -42.4 -406.3] e
172.881 462.292 172.881 462.292 tbx
0 tal
8 tld
/_ArialMT 7 tfn
(4) 172.881 455.957 tpt
T
[1.33 0 0 1.33 -41.39 -406.5] e
173.184 452.29 173.184 452.29 tbx
0 tal
8 tld
/_ArialMT 7 tfn
(5) 173.184 445.955 tpt
T
[1.33 0 0 1.33 -41.99 -405.9] e
171.062 441.984 171.062 441.984 tbx
0 tal
8 tld
/_ArialMT 7 tfn
(6) 171.062 435.649 tpt
T
[1.33 0 0 1.33 -42.4 -407.5] e
165.909 433.951 165.909 433.951 tbx
0 tal
8 tld
/_ArialMT 7 tfn
(7) 165.909 427.616 tpt
T
[1.33 0 0 1.33 -42.6 -406.9] e
157.574 427.434 157.574 427.434 tbx
0 tal
8 tld
/_ArialMT 7 tfn
(8) 157.574 421.099 tpt
T
[1.33 0 0 1.33 -42.8 -407.1] e
148.026 424.1 148.026 424.1 tbx
0 tal
8 tld
/_ArialMT 7 tfn
(9) 148.026 417.765 tpt
T
[1.33 0 0 1.33 -43.4 -407.8] e
135.901 424.554 135.901 424.554 tbx
0 tal
8 tld
/_ArialMT 7 tfn
(10) 135.901 418.219 tpt
T
[1.33 0 0 1.33 -44.01 -407.1] e
126.808 427.282 126.808 427.282 tbx
0 tal
8 tld
/_ArialMT 7 tfn
(11) 126.808 420.947 tpt
T
[1.33 0 0 1.33 -44.61 -406.9] e
118.775 433.799 118.775 433.799 tbx
0 tal
8 tld
/_ArialMT 7 tfn
(12) 118.775 427.464 tpt
T
[1.33 0 0 1.33 -40.38 -410.4] e
109.833 445.015 109.833 445.015 tbx
0 tal
8 tld
/_ArialMT 7 tfn
(13) 109.833 438.68 tpt
T
[1.33 0 0 1.33 -44.01 -407.8] e
110.136 452.896 110.136 452.896 tbx
0 tal
8 tld
/_ArialMT 7 tfn
(14) 110.136 446.561 tpt
T
[1.33 0 0 1.33 -43.2 -408] e
110.288 463.353 110.288 463.353 tbx
0 tal
8 tld
/_ArialMT 7 tfn
(15) 110.288 457.018 tpt
T
[1.33 0 0 1.33 -43.6 -408.2] e
114.986 472.901 114.986 472.901 tbx
0 tal
8 tld
/_ArialMT 7 tfn
(16) 114.986 466.566 tpt
T
U
U
-1.42109e-016 -1.42109e-016 -1.42109e-016 0 k
1 1 1 0 K
1 w
q
1 0 0 1 0 0 cm
81 54 m
85.3 54 L
Q
S
q
1 0 0 1 0 0 cm
469.4 54 m
465.1 54 L
Q
S
u
[1 0 0 1 84.34 45.82] e
-10.008 16.29 -10.008 16.29 tbx
2 tal
15 tld
1 1 1 0 k
/_ArialMT 14 tfn
(0) -17.792 3.62 tpt
T
[1 0 0 1 99.35 94.22] e
-25.02 16.29 -25.02 16.29 tbx
2 tal
15 tld
/_ArialMT 14 tfn
(0.2) -44.48 3.62 tpt
T
[1 0 0 1 99.35 142.6] e
-25.02 16.29 -25.02 16.29 tbx
2 tal
15 tld
/_ArialMT 14 tfn
(0.4) -44.48 3.62 tpt
T
[1 0 0 1 99.35 191] e
-25.02 16.29 -25.02 16.29 tbx
2 tal
15 tld
/_ArialMT 14 tfn
(0.6) -44.48 3.62 tpt
T
[1 0 0 1 99.35 239.4] e
-25.02 16.29 -25.02 16.29 tbx
2 tal
15 tld
/_ArialMT 14 tfn
(0.8) -44.48 3.62 tpt
T
[1 0 0 1 84.34 287.8] e
-10.008 16.29 -10.008 16.29 tbx
2 tal
15 tld
/_ArialMT 14 tfn
(1) -17.792 3.62 tpt
T
U
-1.42109e-016 -1.42109e-016 -1.42109e-016 0 k
q
1 0 0 1 0 0 cm
81 102.4 m
85.3 102.4 L
Q
S
q
1 0 0 1 0 0 cm
469.4 102.4 m
465.1 102.4 L
Q
S
q
1 0 0 1 0 0 cm
81 150.8 m
85.3 150.8 L
Q
S
q
1 0 0 1 0 0 cm
469.4 150.8 m
465.1 150.8 L
Q
S
q
1 0 0 1 0 0 cm
81 199.2 m
85.3 199.2 L
Q
S
q
1 0 0 1 0 0 cm
469.4 199.2 m
465.1 199.2 L
Q
S
q
1 0 0 1 0 0 cm
81 247.6 m
85.3 247.6 L
Q
S
q
1 0 0 1 0 0 cm
469.4 247.6 m
465.1 247.6 L
Q
S
q
1 0 0 1 0 0 cm
81 296 m
85.3 296 L
Q
S
q
1 0 0 1 0 0 cm
469.4 296 m
465.1 296 L
Q
S
q
1 0 0 1 0 0 cm
81 54 m
81 58.3 L
Q
S
q
1 0 0 1 0 0 cm
81 296 m
81 291.7 L
Q
S
u
[1 0 0 1 103.3 33.26] e
-17.514 16.29 -17.514 16.29 tbx
1 tal
15 tld
1 1 1 0 k
/_ArialMT 14 tfn
(0.01) -31.136 3.62 tpt
T
[1 0 0 1 191.2 33.26] e
-12.51 16.29 -12.51 16.29 tbx
1 tal
15 tld
/_ArialMT 14 tfn
(0.1) -22.24 3.62 tpt
T
[1 0 0 1 279.6 33.26] e
-5.004 16.29 -5.004 16.29 tbx
1 tal
15 tld
/_ArialMT 14 tfn
(1) -8.896 3.62 tpt
T
[1 0 0 1 383.2 33.26] e
-10.008 16.29 -10.008 16.29 tbx
1 tal
15 tld
/_ArialMT 14 tfn
(10) -17.792 3.62 tpt
T
[1 0 0 1 482.5 33.26] e
-15.012 16.29 -15.012 16.29 tbx
1 tal
15 tld
/_ArialMT 14 tfn
(100) -26.688 3.62 tpt
T
U
-1.42109e-016 -1.42109e-016 -1.42109e-016 0 k
q
1 0 0 1 0 0 cm
110.2 54 m
110.2 56.1 L
Q
S
q
1 0 0 1 0 0 cm
110.2 296 m
110.2 293.9 L
Q
S
q
1 0 0 1 0 0 cm
127.3 54 m
127.3 56.1 L
Q
S
q
1 0 0 1 0 0 cm
127.3 296 m
127.3 293.9 L
Q
S
q
1 0 0 1 0 0 cm
139.5 54 m
139.5 56.1 L
Q
S
q
1 0 0 1 0 0 cm
139.5 296 m
139.5 293.9 L
Q
S
q
1 0 0 1 0 0 cm
148.9 54 m
148.9 56.1 L
Q
S
q
1 0 0 1 0 0 cm
148.9 296 m
148.9 293.9 L
Q
S
q
1 0 0 1 0 0 cm
156.6 54 m
156.6 56.1 L
Q
S
q
1 0 0 1 0 0 cm
156.6 296 m
156.6 293.9 L
Q
S
q
1 0 0 1 0 0 cm
163.1 54 m
163.1 56.1 L
Q
S
q
1 0 0 1 0 0 cm
163.1 296 m
163.1 293.9 L
Q
S
q
1 0 0 1 0 0 cm
168.7 54 m
168.7 56.1 L
Q
S
q
1 0 0 1 0 0 cm
168.7 296 m
168.7 293.9 L
Q
S
q
1 0 0 1 0 0 cm
173.7 54 m
173.7 56.1 L
Q
S
q
1 0 0 1 0 0 cm
173.7 296 m
173.7 293.9 L
Q
S
q
1 0 0 1 0 0 cm
178.1 54 m
178.1 58.3 L
Q
S
q
1 0 0 1 0 0 cm
178.1 296 m
178.1 291.7 L
Q
S
q
1 0 0 1 0 0 cm
207.3 54 m
207.3 56.1 L
Q
S
q
1 0 0 1 0 0 cm
207.3 296 m
207.3 293.9 L
Q
S
q
1 0 0 1 0 0 cm
224.4 54 m
224.4 56.1 L
Q
S
q
1 0 0 1 0 0 cm
224.4 296 m
224.4 293.9 L
Q
S
q
1 0 0 1 0 0 cm
236.6 54 m
236.6 56.1 L
Q
S
q
1 0 0 1 0 0 cm
236.6 296 m
236.6 293.9 L
Q
S
q
1 0 0 1 0 0 cm
246 54 m
246 56.1 L
Q
S
q
1 0 0 1 0 0 cm
246 296 m
246 293.9 L
Q
S
q
1 0 0 1 0 0 cm
253.7 54 m
253.7 56.1 L
Q
S
q
1 0 0 1 0 0 cm
253.7 296 m
253.7 293.9 L
Q
S
q
1 0 0 1 0 0 cm
260.2 54 m
260.2 56.1 L
Q
S
q
1 0 0 1 0 0 cm
260.2 296 m
260.2 293.9 L
Q
S
q
1 0 0 1 0 0 cm
265.8 54 m
265.8 56.1 L
Q
S
q
1 0 0 1 0 0 cm
265.8 296 m
265.8 293.9 L
Q
S
q
1 0 0 1 0 0 cm
270.8 54 m
270.8 56.1 L
Q
S
q
1 0 0 1 0 0 cm
270.8 296 m
270.8 293.9 L
Q
S
q
1 0 0 1 0 0 cm
275.2 54 m
275.2 58.3 L
Q
S
q
1 0 0 1 0 0 cm
275.2 296 m
275.2 291.7 L
Q
S
q
1 0 0 1 0 0 cm
304.4 54 m
304.4 56.1 L
Q
S
q
1 0 0 1 0 0 cm
304.4 296 m
304.4 293.9 L
Q
S
q
1 0 0 1 0 0 cm
321.5 54 m
321.5 56.1 L
Q
S
q
1 0 0 1 0 0 cm
321.5 296 m
321.5 293.9 L
Q
S
q
1 0 0 1 0 0 cm
333.7 54 m
333.7 56.1 L
Q
S
q
1 0 0 1 0 0 cm
333.7 296 m
333.7 293.9 L
Q
S
q
1 0 0 1 0 0 cm
343.1 54 m
343.1 56.1 L
Q
S
q
1 0 0 1 0 0 cm
343.1 296 m
343.1 293.9 L
Q
S
q
1 0 0 1 0 0 cm
350.8 54 m
350.8 56.1 L
Q
S
q
1 0 0 1 0 0 cm
350.8 296 m
350.8 293.9 L
Q
S
q
1 0 0 1 0 0 cm
357.3 54 m
357.3 56.1 L
Q
S
q
1 0 0 1 0 0 cm
357.3 296 m
357.3 293.9 L
Q
S
q
1 0 0 1 0 0 cm
362.9 54 m
362.9 56.1 L
Q
S
q
1 0 0 1 0 0 cm
362.9 296 m
362.9 293.9 L
Q
S
q
1 0 0 1 0 0 cm
367.9 54 m
367.9 56.1 L
Q
S
q
1 0 0 1 0 0 cm
367.9 296 m
367.9 293.9 L
Q
S
q
1 0 0 1 0 0 cm
372.3 54 m
372.3 58.3 L
Q
S
q
1 0 0 1 0 0 cm
372.3 296 m
372.3 291.7 L
Q
S
q
1 0 0 1 0 0 cm
401.5 54 m
401.5 56.1 L
Q
S
q
1 0 0 1 0 0 cm
401.5 296 m
401.5 293.9 L
Q
S
q
1 0 0 1 0 0 cm
418.6 54 m
418.6 56.1 L
Q
S
q
1 0 0 1 0 0 cm
418.6 296 m
418.6 293.9 L
Q
S
q
1 0 0 1 0 0 cm
430.8 54 m
430.8 56.1 L
Q
S
q
1 0 0 1 0 0 cm
430.8 296 m
430.8 293.9 L
Q
S
q
1 0 0 1 0 0 cm
440.2 54 m
440.2 56.1 L
Q
S
q
1 0 0 1 0 0 cm
440.2 296 m
440.2 293.9 L
Q
S
q
1 0 0 1 0 0 cm
447.9 54 m
447.9 56.1 L
Q
S
q
1 0 0 1 0 0 cm
447.9 296 m
447.9 293.9 L
Q
S
q
1 0 0 1 0 0 cm
454.4 54 m
454.4 56.1 L
Q
S
q
1 0 0 1 0 0 cm
454.4 296 m
454.4 293.9 L
Q
S
q
1 0 0 1 0 0 cm
460 54 m
460 56.1 L
Q
S
q
1 0 0 1 0 0 cm
460 296 m
460 293.9 L
Q
S
q
1 0 0 1 0 0 cm
465 54 m
465 56.1 L
Q
S
q
1 0 0 1 0 0 cm
465 296 m
465 293.9 L
Q
S
q
1 0 0 1 0 0 cm
469.4 54 m
469.4 58.3 L
Q
S
q
1 0 0 1 0 0 cm
469.4 296 m
469.4 291.7 L
Q
S
[0 1 -1 0 41.99 263.9] e
-89.037 16.29 -89.037 16.29 tbx
1 tal
17 tld
1 1 1 0 k
/_ArialMT 16 tfn
(Occupation probability) -168.181 1.81 tpt
T
[1 0 0 1 391.6 10.03] e
-116.037 16.29 -116.037 16.29 tbx
1 tal
17 tld
/_ArialMT 16 tfn
(Time t  [inverse jumping rate]) -219.181 1.81 tpt
T
u
u
-1.42109e-016 -1.42109e-016 -1.42109e-016 0 k
[10 4 3 4] 0 d
q
1 0 0 1 6.574 -25.63 cm
400.3 282.7 m
447.8 282.7 L
Q
S
[10 4] 0 d
q
1 0 0 1 6.574 3.544 cm
400.3 264.7 m
447.8 264.7 L
Q
S
[] 0 d
q
1 0 0 1 6.574 32.71 cm
400.3 246.7 m
447.8 246.7 L
Q
S
[10 4 3 4 3 4] 0 d
q
1 0 0 1 6.574 17.21 cm
400.3 228.7 m
447.8 228.7 L
Q
S
[3 3] 0 d
q
1 0 0 1 6.574 24.04 cm
400.3 210.7 m
447.8 210.7 L
Q
S
0.498039 0.498039 0.498039 0 K
[] 0 d
q
1 0 0 1 6.574 30.87 cm
400.3 192.7 m
447.8 192.7 L
Q
S
[10 4] 0 d
q
1 0 0 1 6.574 37.7 cm
400.3 174.7 m
447.8 174.7 L
Q
S
[10 4 3 4] 0 d
q
1 0 0 1 6.574 44.53 cm
400.3 156.7 m
447.8 156.7 L
Q
S
[10 4 3 4 3 4] 0 d
q
1 0 0 1 6.574 51.36 cm
400.3 138.7 m
447.8 138.7 L
Q
S
[3 3] 0 d
q
1 0 0 1 6.574 58.19 cm
400.3 120.7 m
447.8 120.7 L
Q
S
0.25098 0.25098 0.25098 0 K
0.75 w
q
1 0 0 1 7.574 65.02 cm
400.3 102.7 m
447.8 102.7 L
Q
S
[1 0 0 1 21.76 0.8688] e
377.624 283.609 377.624 283.609 tbx
2 tal
11 tld
1 1 1 0 k
/_ArialMT 10 tfn
(0) 372.064 274.559 tpt
(\r) TX
(1) 372.064 263.559 tpt
(\r) TX
(2) 372.064 252.559 tpt
(\r) TX
(3) 372.064 241.559 tpt
(\r) TX
(4) 372.064 230.559 tpt
(\r) TX
(5) 372.064 219.559 tpt
(\r) TX
(6) 372.064 208.559 tpt
(\r) TX
(7) 372.064 197.559 tpt
(\r) TX
(8) 372.064 186.559 tpt
(\r) TX
(9) 372.064 175.559 tpt
(\r) TX
(eq) 366.504 164.559 tpt
T
U
-1.42109e-016 -1.42109e-016 -1.42109e-016 0 k
0.5 w
[] 0 d
455.492 162.072 379.728 288.87 [1 0 0 1 4.209 -1.578] Bx
s
U
1 1 1 0 K
1 w
[10 4 3 4] 0 d
q
1 0 0 1 0 0 cm
81 293.6 m
81 293.6 L
84.9 293.4 L
88.8 293.1 L
92.7 292.9 L
96.5 292.6 L
100.4 292.3 L
104.3 291.9 L
108.2 291.5 L
112.1 291.1 L
116 290.6 L
119.8 290.1 L
123.7 289.6 L
127.6 289 L
131.5 288.4 L
135.4 287.7 L
139.3 286.9 L
143.1 286.1 L
147 285.2 L
150.9 284.2 L
154.8 283.2 L
158.7 282.1 L
162.6 280.9 L
166.4 279.6 L
170.3 278.2 L
174.2 276.7 L
178.1 275.1 L
182 273.3 L
185.9 271.5 L
189.8 269.6 L
193.6 267.5 L
197.5 265.4 L
201.4 263.1 L
205.3 260.7 L
209.2 258.2 L
213.1 255.6 L
216.9 252.9 L
220.8 250.1 L
224.7 247.3 L
228.6 244.4 L
232.5 241.5 L
236.4 238.6 L
240.2 235.6 L
244.1 232.7 L
248 229.8 L
251.9 227 L
255.8 224.2 L
259.7 221.6 L
263.5 219 L
267.4 216.6 L
271.3 214.2 L
275.2 211.9 L
279.1 209.8 L
283 207.7 L
286.9 205.7 L
290.7 203.8 L
294.6 201.8 L
298.5 199.9 L
302.4 197.9 L
306.3 195.9 L
310.2 193.9 L
314 191.7 L
317.9 189.4 L
321.8 187.1 L
325.7 184.6 L
329.6 182 L
333.5 179.3 L
337.3 176.5 L
341.2 173.6 L
345.1 170.6 L
349 167.5 L
352.9 164.3 L
356.8 161.2 L
360.6 157.9 L
364.5 154.7 L
368.4 151.5 L
372.3 148.4 L
376.2 145.3 L
380.1 142.2 L
384 139.3 L
387.8 136.5 L
391.7 133.8 L
395.6 131.4 L
399.5 129.1 L
403.4 127 L
407.3 125.2 L
411.1 123.6 L
415 122.2 L
418.9 121.1 L
422.8 120.2 L
426.7 119.4 L
430.6 118.9 L
434.4 118.5 L
438.3 118.2 L
442.2 118 L
446.1 117.9 L
450 117.8 L
453.9 117.7 L
457.7 117.7 L
461.6 117.7 L
465.5 117.7 L
469.4 117.7 L
Q
S
[10 4] 0 d
q
1 0 0 1 0 0 cm
81 296 m
81 296 L
84.9 296 L
88.8 296 L
92.7 296 L
96.5 296 L
100.4 296 L
104.3 296 L
108.2 296 L
112.1 295.9 L
116 295.9 L
119.8 295.9 L
123.7 295.9 L
127.6 295.9 L
131.5 295.9 L
135.4 295.8 L
139.3 295.8 L
143.1 295.8 L
147 295.7 L
150.9 295.7 L
154.8 295.6 L
158.7 295.6 L
162.6 295.5 L
166.4 295.4 L
170.3 295.3 L
174.2 295.1 L
178.1 295 L
182 294.8 L
185.9 294.6 L
189.8 294.3 L
193.6 294 L
197.5 293.6 L
201.4 293.2 L
205.3 292.8 L
209.2 292.2 L
213.1 291.6 L
216.9 290.8 L
220.8 290 L
224.7 289.1 L
228.6 288 L
232.5 286.8 L
236.4 285.4 L
240.2 283.9 L
244.1 282.3 L
248 280.4 L
251.9 278.4 L
255.8 276.2 L
259.7 273.8 L
263.5 271.2 L
267.4 268.4 L
271.3 265.5 L
275.2 262.4 L
279.1 259.1 L
283 255.6 L
286.9 252 L
290.7 248.2 L
294.6 244.3 L
298.5 240.3 L
302.4 236.1 L
306.3 231.8 L
310.2 227.4 L
314 222.9 L
317.9 218.4 L
321.8 213.7 L
325.7 209.1 L
329.6 204.4 L
333.5 199.6 L
337.3 194.9 L
341.2 190.2 L
345.1 185.6 L
349 181 L
352.9 176.4 L
356.8 171.9 L
360.6 167.6 L
364.5 163.3 L
368.4 159.1 L
372.3 155 L
376.2 151.1 L
380.1 147.3 L
384 143.7 L
387.8 140.3 L
391.7 137.1 L
395.6 134.1 L
399.5 131.4 L
403.4 128.9 L
407.3 126.7 L
411.1 124.8 L
415 123.1 L
418.9 121.8 L
422.8 120.7 L
426.7 119.8 L
430.6 119.1 L
434.4 118.6 L
438.3 118.3 L
442.2 118 L
446.1 117.9 L
450 117.8 L
453.9 117.7 L
457.7 117.7 L
461.6 117.7 L
465.5 117.7 L
469.4 117.7 L
Q
S
[] 0 d
q
1 0 0 1 0 0 cm
81 296 m
81 296 L
84.9 296 L
88.8 296 L
92.7 296 L
96.5 296 L
100.4 296 L
104.3 296 L
108.2 296 L
112.1 296 L
116 296 L
119.8 296 L
123.7 296 L
127.6 296 L
131.5 296 L
135.4 296 L
139.3 296 L
143.1 296 L
147 296 L
150.9 296 L
154.8 296 L
158.7 296 L
162.6 296 L
166.4 296 L
170.3 296 L
174.2 295.9 L
178.1 295.9 L
182 295.9 L
185.9 295.9 L
189.8 295.9 L
193.6 295.8 L
197.5 295.8 L
201.4 295.7 L
205.3 295.6 L
209.2 295.5 L
213.1 295.3 L
216.9 295.2 L
220.8 294.9 L
224.7 294.7 L
228.6 294.3 L
232.5 293.9 L
236.4 293.4 L
240.2 292.7 L
244.1 291.9 L
248 291 L
251.9 289.9 L
255.8 288.6 L
259.7 287 L
263.5 285.2 L
267.4 283.1 L
271.3 280.7 L
275.2 278 L
279.1 274.9 L
283 271.6 L
286.9 267.9 L
290.7 263.9 L
294.6 259.6 L
298.5 255 L
302.4 250.2 L
306.3 245.1 L
310.2 239.9 L
314 234.6 L
317.9 229.2 L
321.8 223.7 L
325.7 218.1 L
329.6 212.6 L
333.5 207.1 L
337.3 201.7 L
341.2 196.3 L
345.1 191 L
349 185.8 L
352.9 180.7 L
356.8 175.8 L
360.6 171 L
364.5 166.3 L
368.4 161.7 L
372.3 157.4 L
376.2 153.2 L
380.1 149.1 L
384 145.3 L
387.8 141.6 L
391.7 138.2 L
395.6 135.1 L
399.5 132.2 L
403.4 129.5 L
407.3 127.2 L
411.1 125.2 L
415 123.4 L
418.9 122 L
422.8 120.8 L
426.7 119.9 L
430.6 119.2 L
434.4 118.7 L
438.3 118.3 L
442.2 118.1 L
446.1 117.9 L
450 117.8 L
453.9 117.7 L
457.7 117.7 L
461.6 117.7 L
465.5 117.7 L
469.4 117.7 L
Q
S
[10 4 3 4 3 4] 0 d
q
1 0 0 1 0 0 cm
81 56.4 m
81 56.4 L
84.9 56.6 L
88.8 56.9 L
92.7 57.1 L
96.5 57.4 L
100.4 57.7 L
104.3 58.1 L
108.2 58.5 L
112.1 58.9 L
116 59.4 L
119.8 59.9 L
123.7 60.4 L
127.6 61 L
131.5 61.6 L
135.4 62.3 L
139.3 63.1 L
143.1 63.9 L
147 64.8 L
150.9 65.8 L
154.8 66.8 L
158.7 67.9 L
162.6 69.1 L
166.4 70.4 L
170.3 71.8 L
174.2 73.3 L
178.1 74.9 L
182 76.7 L
185.9 78.5 L
189.8 80.4 L
193.6 82.5 L
197.5 84.6 L
201.4 86.9 L
205.3 89.3 L
209.2 91.8 L
213.1 94.4 L
216.9 97.1 L
220.8 99.9 L
224.7 102.7 L
228.6 105.6 L
232.5 108.5 L
236.4 111.4 L
240.2 114.4 L
244.1 117.3 L
248 120.1 L
251.9 123 L
255.8 125.7 L
259.7 128.3 L
263.5 130.8 L
267.4 133.2 L
271.3 135.5 L
275.2 137.6 L
279.1 139.6 L
283 141.4 L
286.9 143.1 L
290.7 144.7 L
294.6 146.1 L
298.5 147.4 L
302.4 148.5 L
306.3 149.5 L
310.2 150.3 L
314 150.9 L
317.9 151.4 L
321.8 151.7 L
325.7 151.8 L
329.6 151.7 L
333.5 151.4 L
337.3 150.9 L
341.2 150.2 L
345.1 149.2 L
349 148.1 L
352.9 146.8 L
356.8 145.4 L
360.6 143.7 L
364.5 142 L
368.4 140.2 L
372.3 138.3 L
376.2 136.4 L
380.1 134.4 L
384 132.5 L
387.8 130.6 L
391.7 128.8 L
395.6 127.1 L
399.5 125.6 L
403.4 124.2 L
407.3 122.9 L
411.1 121.8 L
415 120.8 L
418.9 120 L
422.8 119.4 L
426.7 118.9 L
430.6 118.5 L
434.4 118.2 L
438.3 118 L
442.2 117.9 L
446.1 117.8 L
450 117.8 L
453.9 117.7 L
457.7 117.7 L
461.6 117.7 L
465.5 117.7 L
469.4 117.7 L
Q
S
[3 3] 0 d
q
1 0 0 1 0 0 cm
81 54 m
81 54 L
84.9 54 L
88.8 54 L
92.7 54 L
96.5 54 L
100.4 54 L
104.3 54 L
108.2 54 L
112.1 54.1 L
116 54.1 L
119.8 54.1 L
123.7 54.1 L
127.6 54.1 L
131.5 54.1 L
135.4 54.2 L
139.3 54.2 L
143.1 54.2 L
147 54.3 L
150.9 54.3 L
154.8 54.4 L
158.7 54.4 L
162.6 54.5 L
166.4 54.6 L
170.3 54.7 L
174.2 54.9 L
178.1 55 L
182 55.2 L
185.9 55.4 L
189.8 55.7 L
193.6 56 L
197.5 56.4 L
201.4 56.8 L
205.3 57.2 L
209.2 57.8 L
213.1 58.4 L
216.9 59.1 L
220.8 60 L
224.7 60.9 L
228.6 61.9 L
232.5 63.1 L
236.4 64.4 L
240.2 65.9 L
244.1 67.5 L
248 69.3 L
251.9 71.2 L
255.8 73.3 L
259.7 75.5 L
263.5 77.8 L
267.4 80.3 L
271.3 82.9 L
275.2 85.6 L
279.1 88.3 L
283 91.1 L
286.9 93.9 L
290.7 96.8 L
294.6 99.6 L
298.5 102.3 L
302.4 105.1 L
306.3 107.7 L
310.2 110.2 L
314 112.7 L
317.9 114.9 L
321.8 117.1 L
325.7 119 L
329.6 120.8 L
333.5 122.4 L
337.3 123.8 L
341.2 124.9 L
345.1 125.8 L
349 126.5 L
352.9 126.9 L
356.8 127.1 L
360.6 127.1 L
364.5 127 L
368.4 126.6 L
372.3 126.1 L
376.2 125.5 L
380.1 124.8 L
384 124.1 L
387.8 123.4 L
391.7 122.6 L
395.6 121.9 L
399.5 121.2 L
403.4 120.6 L
407.3 120 L
411.1 119.5 L
415 119.1 L
418.9 118.7 L
422.8 118.5 L
426.7 118.2 L
430.6 118.1 L
434.4 117.9 L
438.3 117.8 L
442.2 117.8 L
446.1 117.7 L
450 117.7 L
453.9 117.7 L
457.7 117.7 L
461.6 117.7 L
465.5 117.7 L
469.4 117.7 L
Q
S
0.498039 0.498039 0.498039 0 K
[] 0 d
q
1 0 0 1 0 0 cm
81 54 m
81 54 L
84.9 54 L
88.8 54 L
92.7 54 L
96.5 54 L
100.4 54 L
104.3 54 L
108.2 54 L
112.1 54 L
116 54 L
119.8 54 L
123.7 54 L
127.6 54 L
131.5 54 L
135.4 54 L
139.3 54 L
143.1 54 L
147 54 L
150.9 54 L
154.8 54 L
158.7 54 L
162.6 54 L
166.4 54 L
170.3 54 L
174.2 54 L
178.1 54 L
182 54 L
185.9 54.1 L
189.8 54.1 L
193.6 54.1 L
197.5 54.1 L
201.4 54.2 L
205.3 54.2 L
209.2 54.3 L
213.1 54.3 L
216.9 54.4 L
220.8 54.5 L
224.7 54.7 L
228.6 54.8 L
232.5 55.1 L
236.4 55.3 L
240.2 55.6 L
244.1 56 L
248 56.5 L
251.9 57.1 L
255.8 57.7 L
259.7 58.5 L
263.5 59.4 L
267.4 60.5 L
271.3 61.7 L
275.2 63 L
279.1 64.5 L
283 66.2 L
286.9 68.1 L
290.7 70.1 L
294.6 72.2 L
298.5 74.5 L
302.4 76.9 L
306.3 79.4 L
310.2 81.9 L
314 84.5 L
317.9 87.2 L
321.8 89.8 L
325.7 92.4 L
329.6 94.9 L
333.5 97.4 L
337.3 99.7 L
341.2 101.9 L
345.1 104 L
349 105.9 L
352.9 107.6 L
356.8 109.1 L
360.6 110.4 L
364.5 111.6 L
368.4 112.5 L
372.3 113.4 L
376.2 114.1 L
380.1 114.6 L
384 115.1 L
387.8 115.5 L
391.7 115.9 L
395.6 116.2 L
399.5 116.5 L
403.4 116.7 L
407.3 116.9 L
411.1 117.1 L
415 117.2 L
418.9 117.3 L
422.8 117.4 L
426.7 117.5 L
430.6 117.6 L
434.4 117.6 L
438.3 117.6 L
442.2 117.7 L
446.1 117.7 L
450 117.7 L
453.9 117.7 L
457.7 117.7 L
461.6 117.7 L
465.5 117.7 L
469.4 117.7 L
Q
S
[10 4] 0 d
q
1 0 0 1 0 0 cm
81 54 m
81 54 L
84.9 54 L
88.8 54 L
92.7 54 L
96.5 54 L
100.4 54 L
104.3 54 L
108.2 54 L
112.1 54 L
116 54 L
119.8 54 L
123.7 54 L
127.6 54 L
131.5 54 L
135.4 54 L
139.3 54 L
143.1 54 L
147 54 L
150.9 54 L
154.8 54 L
158.7 54 L
162.6 54 L
166.4 54 L
170.3 54 L
174.2 54 L
178.1 54 L
182 54 L
185.9 54 L
189.8 54 L
193.6 54 L
197.5 54 L
201.4 54 L
205.3 54 L
209.2 54 L
213.1 54 L
216.9 54 L
220.8 54 L
224.7 54 L
228.6 54.1 L
232.5 54.1 L
236.4 54.1 L
240.2 54.2 L
244.1 54.2 L
248 54.3 L
251.9 54.4 L
255.8 54.6 L
259.7 54.7 L
263.5 55 L
267.4 55.2 L
271.3 55.6 L
275.2 56 L
279.1 56.6 L
283 57.2 L
286.9 58 L
290.7 58.9 L
294.6 60 L
298.5 61.2 L
302.4 62.6 L
306.3 64.2 L
310.2 65.9 L
314 67.8 L
317.9 69.8 L
321.8 71.9 L
325.7 74.2 L
329.6 76.5 L
333.5 78.9 L
337.3 81.4 L
341.2 83.8 L
345.1 86.3 L
349 88.7 L
352.9 91 L
356.8 93.3 L
360.6 95.5 L
364.5 97.5 L
368.4 99.5 L
372.3 101.4 L
376.2 103.2 L
380.1 104.9 L
384 106.5 L
387.8 108 L
391.7 109.4 L
395.6 110.7 L
399.5 111.9 L
403.4 112.9 L
407.3 113.9 L
411.1 114.7 L
415 115.4 L
418.9 116 L
422.8 116.4 L
426.7 116.8 L
430.6 117.1 L
434.4 117.3 L
438.3 117.4 L
442.2 117.5 L
446.1 117.6 L
450 117.6 L
453.9 117.7 L
457.7 117.7 L
461.6 117.7 L
465.5 117.7 L
469.4 117.7 L
Q
S
[10 4 3 4] 0 d
q
1 0 0 1 0 0 cm
81 54 m
81 54 L
84.9 54 L
88.8 54 L
92.7 54 L
96.5 54 L
100.4 54 L
104.3 54 L
108.2 54 L
112.1 54 L
116 54 L
119.8 54 L
123.7 54 L
127.6 54 L
131.5 54 L
135.4 54 L
139.3 54 L
143.1 54 L
147 54 L
150.9 54 L
154.8 54 L
158.7 54 L
162.6 54 L
166.4 54 L
170.3 54 L
174.2 54 L
178.1 54 L
182 54 L
185.9 54 L
189.8 54 L
193.6 54 L
197.5 54 L
201.4 54 L
205.3 54 L
209.2 54 L
213.1 54 L
216.9 54 L
220.8 54 L
224.7 54 L
228.6 54 L
232.5 54 L
236.4 54 L
240.2 54 L
244.1 54 L
248 54 L
251.9 54 L
255.8 54.1 L
259.7 54.1 L
263.5 54.1 L
267.4 54.2 L
271.3 54.3 L
275.2 54.4 L
279.1 54.5 L
283 54.7 L
286.9 55 L
290.7 55.3 L
294.6 55.7 L
298.5 56.2 L
302.4 56.8 L
306.3 57.5 L
310.2 58.4 L
314 59.4 L
317.9 60.6 L
321.8 62 L
325.7 63.5 L
329.6 65.2 L
333.5 67.1 L
337.3 69.1 L
341.2 71.3 L
345.1 73.5 L
349 75.9 L
352.9 78.4 L
356.8 80.9 L
360.6 83.6 L
364.5 86.2 L
368.4 88.8 L
372.3 91.5 L
376.2 94.1 L
380.1 96.7 L
384 99.2 L
387.8 101.6 L
391.7 103.8 L
395.6 105.9 L
399.5 107.9 L
403.4 109.7 L
407.3 111.2 L
411.1 112.6 L
415 113.8 L
418.9 114.8 L
422.8 115.6 L
426.7 116.2 L
430.6 116.7 L
434.4 117 L
438.3 117.3 L
442.2 117.4 L
446.1 117.5 L
450 117.6 L
453.9 117.6 L
457.7 117.7 L
461.6 117.7 L
465.5 117.7 L
469.4 117.7 L
Q
S
[10 4 3 4 3 4] 0 d
q
1 0 0 1 0 0 cm
81 54 m
81 54 L
84.9 54 L
88.8 54 L
92.7 54 L
96.5 54 L
100.4 54 L
104.3 54 L
108.2 54 L
112.1 54 L
116 54 L
119.8 54 L
123.7 54 L
127.6 54 L
131.5 54 L
135.4 54 L
139.3 54 L
143.1 54 L
147 54 L
150.9 54 L
154.8 54 L
158.7 54 L
162.6 54 L
166.4 54 L
170.3 54 L
174.2 54 L
178.1 54 L
182 54 L
185.9 54 L
189.8 54 L
193.6 54 L
197.5 54 L
201.4 54 L
205.3 54 L
209.2 54 L
213.1 54 L
216.9 54 L
220.8 54 L
224.7 54 L
228.6 54 L
232.5 54 L
236.4 54 L
240.2 54 L
244.1 54 L
248 54 L
251.9 54 L
255.8 54 L
259.7 54 L
263.5 54 L
267.4 54 L
271.3 54 L
275.2 54.1 L
279.1 54.1 L
283 54.1 L
286.9 54.2 L
290.7 54.3 L
294.6 54.4 L
298.5 54.6 L
302.4 54.8 L
306.3 55.1 L
310.2 55.5 L
314 55.9 L
317.9 56.5 L
321.8 57.3 L
325.7 58.2 L
329.6 59.3 L
333.5 60.5 L
337.3 62 L
341.2 63.7 L
345.1 65.6 L
349 67.8 L
352.9 70.1 L
356.8 72.7 L
360.6 75.4 L
364.5 78.3 L
368.4 81.3 L
372.3 84.4 L
376.2 87.6 L
380.1 90.7 L
384 93.8 L
387.8 96.9 L
391.7 99.8 L
395.6 102.5 L
399.5 105 L
403.4 107.3 L
407.3 109.3 L
411.1 111.1 L
415 112.6 L
418.9 113.9 L
422.8 114.9 L
426.7 115.7 L
430.6 116.3 L
434.4 116.8 L
438.3 117.1 L
442.2 117.3 L
446.1 117.5 L
450 117.6 L
453.9 117.6 L
457.7 117.7 L
461.6 117.7 L
465.5 117.7 L
469.4 117.7 L
Q
S
[3 3] 0 d
q
1 0 0 1 0 0 cm
81 54 m
81 54 L
84.9 54 L
88.8 54 L
92.7 54 L
96.5 54 L
100.4 54 L
104.3 54 L
108.2 54 L
112.1 54 L
116 54 L
119.8 54 L
123.7 54 L
127.6 54 L
131.5 54 L
135.4 54 L
139.3 54 L
143.1 54 L
147 54 L
150.9 54 L
154.8 54 L
158.7 54 L
162.6 54 L
166.4 54 L
170.3 54 L
174.2 54 L
178.1 54 L
182 54 L
185.9 54 L
189.8 54 L
193.6 54 L
197.5 54 L
201.4 54 L
205.3 54 L
209.2 54 L
213.1 54 L
216.9 54 L
220.8 54 L
224.7 54 L
228.6 54 L
232.5 54 L
236.4 54 L
240.2 54 L
244.1 54 L
248 54 L
251.9 54 L
255.8 54 L
259.7 54 L
263.5 54 L
267.4 54 L
271.3 54 L
275.2 54 L
279.1 54 L
283 54 L
286.9 54 L
290.7 54.1 L
294.6 54.1 L
298.5 54.2 L
302.4 54.2 L
306.3 54.4 L
310.2 54.5 L
314 54.8 L
317.9 55.1 L
321.8 55.5 L
325.7 56.1 L
329.6 56.8 L
333.5 57.7 L
337.3 58.9 L
341.2 60.3 L
345.1 61.9 L
349 63.9 L
352.9 66.1 L
356.8 68.6 L
360.6 71.3 L
364.5 74.3 L
368.4 77.5 L
372.3 80.8 L
376.2 84.2 L
380.1 87.6 L
384 91.1 L
387.8 94.4 L
391.7 97.6 L
395.6 100.6 L
399.5 103.5 L
403.4 106 L
407.3 108.3 L
411.1 110.3 L
415 112 L
418.9 113.4 L
422.8 114.6 L
426.7 115.5 L
430.6 116.2 L
434.4 116.7 L
438.3 117.1 L
442.2 117.3 L
446.1 117.5 L
450 117.6 L
453.9 117.6 L
457.7 117.7 L
461.6 117.7 L
465.5 117.7 L
469.4 117.7 L
Q
S
1 1 1 0 K
[] 0 d
q
1 0 0 1 0 0 cm
81 54 m
469.4 54 L
469.4 296 L
81 296 L
81 54 L
Q
S
[1 0 0 1 442.7 326.6] e
-168.57 16.29 -168.57 16.29 tbx
1 tal
0 tld
1 1 1 0 k
/_ArialMT 18 tfn
(Diffusion on a Circle:  5 Atoms on 19 Sites) -337.14 0 tpt
T
[1 0 0 1 14.7 3.841] e
192.05 314.724 192.05 314.724 tbx
0 tal
13 tld
/_ArialMT 12 tfn
(A = 1, B = 1, C = 1, D = 1) 192.05 303.864 tpt
T
%%PageTrailer
_PDX_savepage restore
%%Trailer
end
showpage
%%EOF
