if (((a>x1 && a<x2) && (b>=y1 && b<=y2)) || ((a>=x1 && a<=x2) && (b>y1 && b<y2))){
    bottomLeft=true;
}
if (((a>x1 && a<x2) && (d>=y1 && d<=y2)) || ((a>=x1 && a<=x2) && (d>y1 && d<y2))){
    topLeft=true;
}
if (((c>x1 && c<x2) && (b>=y1 && b<=y2)) || ((c>=x1 && c<=x2) && (b>y1 && b<y2))){
    bottomRight=true;
}
if (((c>x1 && c<x2) && (d>=y1 && d<=y2)) || ((c>=x1 && c<=x2) && (d>y1 && d<y2))){
    topRight=true;
}


if (((x1>a && x2<a) && (y1>=b && y2<=b)) || ((x1>=a && x2<=a) && (y1>b && y2<b))){
    bottomLeft=true;
}
if (((x1>a && x2<a) && (y1>=d && y2<=d)) || ((x1>=a && x2<=a) && (y1>d && y2<d))){
    topLeft=true;
}
if (((x1>c && x2<c) && (y1>=b && y2<=b)) || ((x1>=c && x2<=c) && (y1>b && y2<b))){
    bottomRight=true;
}
if (((x1>c && x2<c) && (y1>=d && y2<=d)) || ((x1>=c && x2<=c) && (y1>d && y2<d))){
    topRight=true;
}
