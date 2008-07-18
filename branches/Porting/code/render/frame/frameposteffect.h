#pragma once
#ifndef FRAME_FRAMEPOSTEFFECT_H
#define FRAME_FRAMEPOSTEFFECT_H
//------------------------------------------------------------------------------
/**
    @class Frame::FramePostEffect
    
    A frame post-effect implements draws a fullscreen quad through a
    shader which implements the post effect.
    
    (C) 2007 Radon Labs GmbH
*/
#include "core/refcounted.h"
#include "resources/resourceid.h"
#include "coregraphics/rendertarget.h"
#include "coregraphics/shaderinstance.h"
#include "coregraphics/shadervariableinstance.h"
#include "coregraphics/vertexbuffer.h"
#include "coregraphics/primitivegroup.h"

//------------------------------------------------------------------------------
namespace Frame
{
class FramePostEffect : public Core::RefCounted
{
    DeclareClass(FramePostEffect);
public:
    /// constructor
    FramePostEffect();
    /// destructor
    virtual ~FramePostEffect();
    /// setup the post effect
    void Setup();
    /// discard the post effect
    void Discard();
    /// render the post effect
    void Render();

    /// set the name of the frame pass
    void SetName(const Resources::ResourceId& resId);
    /// get the name of the frame pass
    const Resources::ResourceId& GetName() const;
    /// set pass shader
    void SetShader(const Ptr<CoreGraphics::ShaderInstance>& shd);
    /// get pass shader
    const Ptr<CoreGraphics::ShaderInstance>& GetShader() const;
    /// set render target
    void SetRenderTarget(const Ptr<CoreGraphics::RenderTarget>& rt);
    /// get render target
    const Ptr<CoreGraphics::RenderTarget>& GetRenderTarget() const;

    /// add a shader variable instance to the frame pass
    void AddVariable(const Ptr<CoreGraphics::ShaderVariableInstance>& var);
    /// get number of shader variables
    SizeT GetNumVariables() const;
    /// get shader variable by index
    const Ptr<CoreGraphics::ShaderVariableInstance>& GetVariableByIndex(IndexT i) const;

private:
    Resources::ResourceId name;
    Ptr<CoreGraphics::VertexBuffer> vertexBuffer;
    Ptr<CoreGraphics::ShaderInstance> shader;
    Ptr<CoreGraphics::RenderTarget> renderTarget;
    Util::Array<Ptr<CoreGraphics::ShaderVariableInstance> > shaderVariables;
    CoreGraphics::PrimitiveGroup primGroup;
    Ptr<CoreGraphics::ShaderVariable> shdPixelSize;
};

//------------------------------------------------------------------------------
/**
*/
inline void
FramePostEffect::SetName(const Resources::ResourceId& resId)
{
    this->name = resId;
}

//------------------------------------------------------------------------------
/**
*/
inline const Resources::ResourceId&
FramePostEffect::GetName() const
{
    return this->name;
}

//------------------------------------------------------------------------------
/**
*/
inline void
FramePostEffect::SetShader(const Ptr<CoreGraphics::ShaderInstance>& shd)
{
    this->shader = shd;
}

//------------------------------------------------------------------------------
/**
*/
inline const Ptr<CoreGraphics::ShaderInstance>&
FramePostEffect::GetShader() const
{
    return this->shader;
}

//------------------------------------------------------------------------------
/**
*/
inline void
FramePostEffect::SetRenderTarget(const Ptr<CoreGraphics::RenderTarget>& rt)
{
    this->renderTarget = rt;
}

//------------------------------------------------------------------------------
/**
*/
inline const Ptr<CoreGraphics::RenderTarget>&
FramePostEffect::GetRenderTarget() const
{
    return this->renderTarget;
}

//------------------------------------------------------------------------------
/**
*/
inline void
FramePostEffect::AddVariable(const Ptr<CoreGraphics::ShaderVariableInstance>& var)
{
    this->shaderVariables.Append(var);
}

//------------------------------------------------------------------------------
/**
*/
inline SizeT
FramePostEffect::GetNumVariables() const
{
    return this->shaderVariables.Size();
}

//------------------------------------------------------------------------------
/**
*/
inline const Ptr<CoreGraphics::ShaderVariableInstance>& 
FramePostEffect::GetVariableByIndex(IndexT i) const
{
    return this->shaderVariables[i];
}

} // namespace Frame
//------------------------------------------------------------------------------
#endif
     