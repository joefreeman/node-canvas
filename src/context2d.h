
//
// context2d.h
//
// Copyright (c) 2010 LearnBoost <tj@learnboost.com>
//

#ifndef __NODE_CONTEXT2D_H__
#define __NODE_CONTEXT2D_H__

#include "canvas.h"

typedef struct {
  unsigned char r, g, b;
  double a;
} rgba_t;

class Context2d: public node::ObjectWrap {
  public:
    rgba_t fill;
    rgba_t stroke;
    static void Initialize(Handle<Object> target);
    static Handle<Value> New(const Arguments &args);
    static Handle<Value> BeginPath(const Arguments &args);
    static Handle<Value> ClosePath(const Arguments &args);
    static Handle<Value> Fill(const Arguments &args);
    static Handle<Value> Stroke(const Arguments &args);
    static Handle<Value> SetFillRGBA(const Arguments &args);
    static Handle<Value> SetStrokeRGBA(const Arguments &args);
    static Handle<Value> BezierCurveTo(const Arguments &args);
    static Handle<Value> LineTo(const Arguments &args);
    static Handle<Value> MoveTo(const Arguments &args);
    static Handle<Value> FillRect(const Arguments &args);
    static Handle<Value> StrokeRect(const Arguments &args);
    static Handle<Value> ClearRect(const Arguments &args);
    static Handle<Value> Arc(const Arguments &args);
    inline cairo_t *getContext(){ return _context; }
    inline Canvas *getCanvas(){ return _canvas; }

  protected:
    Context2d(Canvas *canvas);

  private:
    ~Context2d();
    Canvas *_canvas;
    cairo_t *_context;
};

#endif