#ifndef DOMAttrMapImpl_HEADER_GUARD_
#define DOMAttrMapImpl_HEADER_GUARD_

/*
 * The Apache Software License, Version 1.1
 *
 * Copyright (c) 2001-2002 The Apache Software Foundation.  All rights

 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. The end-user documentation included with the redistribution,
 *    if any, must include the following acknowledgment:
 *       "This product includes software developed by the
 *        Apache Software Foundation (http://www.apache.org/)."
 *    Alternately, this acknowledgment may appear in the software itself,
 *    if and wherever such third-party acknowledgments normally appear.
 *
 * 4. The names "Xerces" and "Apache Software Foundation" must
 *    not be used to endorse or promote products derived from this
 *    software without prior written permission. For written
 *    permission, please contact apache\@apache.org.
 *
 * 5. Products derived from this software may not be called "Apache",
 *    nor may "Apache" appear in their name, without prior written
 *    permission of the Apache Software Foundation.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE APACHE SOFTWARE FOUNDATION OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * ====================================================================
 *
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the Apache Software Foundation, and was
 * originally based on software copyright (c) 2001, International
 * Business Machines, Inc., http://www.ibm.com .  For more information
 * on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 */

/*
 * $Id$
 */

//
//  This file is part of the internal implementation of the C++ XML DOM.
//  It should NOT be included or used directly by application programs.
//
//  Applications should include the file <xercesc/dom/DOM.hpp> for the entire
//  DOM API, or xercesc/dom/DOM*.hpp for individual DOM classes, where the class
//  name is substituded for the *.
//

#include <xercesc/util/XercesDefs.hpp>
#include "DOMNamedNodeMapImpl.hpp"

class DOMNode;
class DOMNamedNodeMap;

class CDOM_EXPORT DOMAttrMapImpl : public DOMNamedNodeMapImpl
{
private:
    bool attrDefaults;

public:
    DOMAttrMapImpl(DOMNode *ownerNod);

    // revisit.  This "copy" constructor is used for cloning an Element with Attributes,
    //                and for setting up default attributes.  It's probably not right
    //                for one or the other or both.
    DOMAttrMapImpl(DOMNode *ownerNod, const DOMNamedNodeMapImpl *defaults);
    DOMAttrMapImpl();

    virtual ~DOMAttrMapImpl();
    virtual DOMAttrMapImpl *cloneAttrMap(DOMNode *ownerNode);
    virtual bool hasDefaults();
    virtual void hasDefaults(bool value);

    virtual DOMNode *removeNamedItem(const XMLCh *name);
    virtual DOMNode *removeNamedItemNS(const XMLCh *namespaceURI, const XMLCh *localName);

    void reconcileDefaultAttributes(const DOMAttrMapImpl* defaults);
    void moveSpecifiedAttributes(DOMAttrMapImpl* srcmap);
};

// ---------------------------------------------------------------------------
//  DOMAttrMapImpl: Getters & Setters
// ---------------------------------------------------------------------------

inline bool DOMAttrMapImpl::hasDefaults()
{
    return attrDefaults;
}

inline void DOMAttrMapImpl::hasDefaults(bool value)
{
    attrDefaults = value;
}


#endif
