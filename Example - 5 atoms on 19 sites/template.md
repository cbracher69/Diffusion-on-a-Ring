%!PS-Adobe-3.0 EPSF-3.0
%%Creator: Mayura Draw, Version 4.1
%%Title: template.md
%%CreationDate: Wed Oct 22 16:30:58 2003
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
u
0.25098 0.25098 0.25098 0 K
0.25 w
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
u
[1 0 0 1 84.34 45.82] e
-10.008 16.29 -10.008 16.29 tbx
2 tal
15 tld
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
u
[1 0 0 1 103.3 33.26] e
-17.514 16.29 -17.514 16.29 tbx
1 tal
15 tld
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
[0 1 -1 0 41.99 263.9] e
-89.037 16.29 -89.037 16.29 tbx
1 tal
17 tld
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
1 1 1 0 K
1 w
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
