%!PS-Adobe-3.0 EPSF-3.0
%%Creator: Mayura Draw, Version 4.0
%%Title: OrbitElements.md
%%CreationDate: Mon Nov 15 15:07:28 2004
%%BoundingBox: 129 286 514 579
%%Orientation: Portrait
%%EndComments
%%BeginProlog
%%BeginResource: procset MayuraDraw_ops
%%Version: 4.0
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

newpath 2 setlinecap 0 setlinejoin 2 setmiterlimit
[] 0 setdash
129 286 moveto 129 579 lineto 514 579 lineto 514 286 lineto closepath clip
newpath
%%EndPageSetup
0.5 w
[3 3] 0 d
q
0.2757 0.9612 -0.9612 0.2757 324.3 -17.51 cm
-173.613 -138.634 211.411 211.411 518.653 211.151 Arc
Q
B
[] 0 d
q
1.2 0 0 1.2 -72.27 -302.2 cm
280.83 645.058 m
339.135 565.824 L
Q
S
126.013 40.5043 158.022 567.05 [1.2 0 0 1.2 106.3 -256.4] Ov
b
0 Pat
109.717 48.8908 191.436 652.972 [-1.091 -0.4987 0.4987 -1.091 182.5 1233] Ov
b
-1 Pat
1 w
q
1 0 0 1 0 0 cm
293.271 434.983 m
489.505 506.039 497.027 508.763 L2
Q
S
q
1 0 0 1 0 0 cm
293.271 434.983 497.027 508.763 4 2 Ah
Q
0.5 w
[3 3] 0 d
q
1 0 0 1 0.3838 29.55 cm
240.437 502.412 238.069 500.57 m2
243.394 504.711 245.745 506.436 247.476 507.468 c
250.084 509.022 256.521 512.1 259.39 513.111 c
262.899 514.349 271.433 516.238 275.068 516.874 c
277.628 517.322 283.73 518.128 286.355 518.128 c
287.34 518.128 288.751 517.971 291.999 517.501 c
Q
S
q
1 0 0 1 0.3838 29.55 cm
247.476 507.468 238.069 500.57 3 1 Ah
Q
1 w
[] 0 d
q
1 0 0 1 -62.89 -82.05 cm
353.957 517.699 m
428.019 576.567 434.282 581.545 L2
Q
S
q
1 0 0 1 -62.89 -82.05 cm
353.957 517.699 434.282 581.545 4 2 Ah
Q
1 1 1 0 k
2.91272 2.91267 136.598 603.504 [1 0 0 1 237.9 -101.9] Ov
b
2.91272 2.91267 136.598 603.504 [1 0 0 1 307.4 -170.4] Ov
b
2.91272 2.91267 136.598 603.504 [1 0 0 1 282.7 -124.1] Ov
b
0 0 0 0 k
0.5 w
q
1.2 0 0 1.2 -72.66 -302.1 cm
338.56 566.628 m
334.67 566.31 332.99 566.173 331.842 566.083 c
329.65 565.912 324.42 565.44 322.219 565.357 c
321.019 565.312 318.154 565.373 316.954 565.357 c
315.382 565.337 311.627 565.196 310.055 565.176 c
308.276 565.152 304.027 565.197 302.248 565.176 c
300.51 565.155 296.36 565.015 294.622 564.994 c
293.63 564.982 291.258 564.966 290.265 564.994 c
288.814 565.036 285.358 565.271 283.91 565.357 c
282.586 565.436 279.425 565.656 278.1 565.72 c
276.901 565.778 274.034 565.819 272.835 565.902 c
271.63 565.985 268.768 566.31 267.57 566.447 c
266.244 566.598 263.084 567.014 261.76 567.173 c
260.313 567.346 256.85 567.707 255.405 567.899 c
254.036 568.081 250.78 568.609 249.414 568.807 c
248.215 568.98 245.346 569.348 244.149 569.533 c
242.697 569.758 239.242 570.374 237.794 570.622 c
236.346 570.871 232.879 571.403 231.439 571.712 c
230.309 571.955 227.654 572.694 226.537 572.983 c
225.09 573.356 221.62 574.199 220.183 574.617 c
218.636 575.066 214.988 576.275 213.465 576.796 c
211.843 577.35 207.983 578.716 206.384 579.337 c
205.087 579.842 202.056 581.2 200.756 581.698 c
199.814 582.058 197.503 582.715 196.58 583.15 c
195.559 583.632 193.344 585.093 192.404 585.692 c
191.523 586.253 189.438 587.62 188.591 588.234 c
187.396 589.099 184.614 591.246 183.508 592.228 c
182.98 592.696 181.789 593.87 181.329 594.407 c
180.824 594.995 179.724 596.457 179.332 597.13 c
178.869 597.924 177.993 599.893 177.698 600.761 c
177.407 601.616 176.829 603.643 176.79 604.574 c
176.753 605.447 177.153 607.384 177.335 608.205 c
177.494 608.925 177.972 610.603 178.242 611.292 c
178.55 612.074 179.39 613.859 179.876 614.56 c
180.373 615.274 181.801 616.696 182.418 617.283 c
182.93 617.771 184.244 618.822 184.779 619.281 c
185.402 619.815 186.838 621.148 187.502 621.641 c
188.253 622.199 190.172 623.313 190.952 623.82 c
191.577 624.226 193.018 625.27 193.675 625.635 c
194.556 626.125 196.775 627 197.669 627.451 c
198.431 627.835 200.169 628.892 200.937 629.266 c
201.707 629.641 203.593 630.407 204.387 630.719 c
205.289 631.073 207.469 631.847 208.381 632.171 c
209.33 632.509 211.599 633.311 212.557 633.624 c
213.503 633.932 215.781 634.609 216.733 634.895 c
217.849 635.23 220.507 636.052 221.635 636.347 c
222.539 636.584 224.721 637.043 225.63 637.255 c
226.665 637.497 229.132 638.105 230.169 638.344 c
231.283 638.602 233.951 639.197 235.071 639.434 c
236.103 639.651 238.573 640.148 239.61 640.341 c
240.807 640.564 243.673 641.053 244.875 641.249 c
245.949 641.424 248.52 641.813 249.595 641.976 c
250.712 642.144 253.378 642.557 254.498 642.702 c
255.612 642.846 258.283 643.117 259.4 643.246 c
260.434 643.366 262.903 643.682 263.939 643.791 c
264.848 643.887 267.021 644.089 267.933 644.154 c
268.718 644.211 270.598 644.27 271.383 644.336 c
272.463 644.426 275.024 644.782 276.103 644.88 c
276.723 644.937 278.207 645.016 278.827 645.062 c
279.199 645.09 279.744 645.135 281.005 645.244 c
Q
B
1 w
q
1.2 0 0 1.2 -8.865 -301.4 cm
249.944 614.169 m
233.857 506.744 232.672 498.832 L2
Q
S
q
1.2 0 0 1.2 -8.865 -301.4 cm
249.944 614.169 232.672 498.832 4 2 Ah
Q
1 1 1 0 k
2.91272 2.91267 136.598 603.504 [1 0 0 1 142.7 -248.7] Ov
b
0 0 0 0 k
289.869 377.085 281.343 404.601 [1 0 0 1 -4.196 -0.9942] Bx
f
289.869 377.085 281.343 404.601 [1 0 0 1 0.3901 8.307] Bx
f
286.963 401.759 285.154 404.601 [0.9786 -0.206 0.206 0.9786 -75.23 77.35] Bx
f
u
0.5 w
23.3016 23.3017 266.353 462.422 [1 0 0 1 24.72 -24.72] Ov
b
23.3017 8.73802 104.675 613.802 [1 0 0 1 186.4 -175.1] Ov
b
U
1 1 1 0 k
1 w
2.91272 2.91267 136.598 603.504 [1 0 0 1 121 -227.1] Ov
b
0 0 0 0 k
q
1 0 0 1 -2.303 1.151 cm
291.999 434.726 m
231.263 547.142 227.46 554.18 L2
Q
S
q
1 0 0 1 -2.303 1.151 cm
291.999 434.726 227.46 554.18 4 2 Ah
Q
q
1.2 0 0 1.2 -71.89 -302.6 cm
399.454 613.224 m
472.963 612.69 480.963 612.631 L2
Q
S
q
1.2 0 0 1.2 -71.89 -302.6 cm
399.454 613.224 480.963 612.631 4 2 Ah
Q
q
1.2 0 0 1.2 -73.04 -302.6 cm
304.117 613.693 m
304.117 719.331 304.117 727.331 L2
Q
S
q
1.2 0 0 1.2 -73.04 -302.6 cm
304.117 613.693 304.117 727.331 4 2 Ah
Q
q
1.2 0 0 1.2 -72.27 -302.2 cm
304.117 613.654 m
236.898 505.624 232.672 498.832 L2
Q
S
q
1.2 0 0 1.2 -72.27 -302.2 cm
304.117 613.654 232.672 498.832 4 2 Ah
Q
0.5 w
270.829 505.054 257.085 518.031 [1 0 0 1 1.535 32.24] Bx
f
274.591 504.644 257.085 518.031 [1 0 0 1 42.22 -178.2] Bx
f
1 w
q
1.2 0 0 1.2 -75.34 -304.1 cm
281.118 646.806 m
386.328 507.84 391.156 501.462 L2
Q
S
q
1.2 0 0 1.2 -75.34 -304.1 cm
281.118 646.806 391.156 501.462 4 2 Ah
Q
1 1 1 0 k
2.91272 2.91267 136.598 603.504 [1 0 0 1 197.2 -227.1] Ov
b
0 0 0 0 k
0.5 w
[3 3] 0 d
q
1 0 0 1 0 0 cm
379.631 505.673 m
418.763 535.538 L
Q
S
q
-0.3605 0.9327 -0.9327 -0.3605 667.5 88.31 cm
-173.613 -109.171 193.986 193.986 518.653 211.151 Arc
Q
S
[] 0 d
274.591 504.644 257.085 518.031 [1 0 0 1 186.4 -111.2] Bx
f
[3 3] 0 d
q
-0.724 -0.6898 0.6898 -0.724 609.6 974.1 cm
158.553 -159.748 75.6694 75.6694 518.653 211.151 Arc
Q
S
[] 0 d
274.591 504.644 257.085 518.031 [1 0 0 1 166.8 4.119] Bx
f
%%PageTrailer
_PDX_savepage restore
%%Trailer
end
showpage
%%EOF